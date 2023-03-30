#include "Character.hpp"
#include "iostream"
#include "Ice.hpp"
#include "Cure.hpp"

Character::Character(): _name("Default Character"){
    std::cout << "Character default constructor called\n";
    for (int i = 0; i < INVENTORY_SIZE; i++)
        this->_inventory[i] = NULL;
    _matHead = NULL;
}

Character::Character(const std::string &name): _name(name) {
    std::cout << "Character constructed with name: " << this->_name << std::endl;
    for (int i = 0; i < INVENTORY_SIZE; i++)
        this->_inventory[i] = NULL;
    _matHead = NULL;
}

Character::Character(const Character &obj):_name(obj._name) {
    std::cout << "Character created by copy\n";
    for (int i = 0; i < INVENTORY_SIZE && obj._inventory[i]; i++) {
        if (obj._inventory[i]->getType() == "ice")
            _inventory[i] = new Ice();
        if (obj._inventory[i]->getType() == "cure")
            _inventory[i] = new Cure();
    }
    Node::copy(obj._matHead, this->_matHead);
}

Character::~Character() {
    std::cout << "Character default destructor called for: " << this->_name << std::endl;
//    for (int i = 0; i < INVENTORY_SIZE; i++)
//       std::cout << _inventory[i]->getType() << std::endl;

    for (int i = 0; i < INVENTORY_SIZE && _inventory[i]; i++) {
        delete _inventory[i];
    }
    Node::freeList(_matHead);
//    delete *_inventory;
}

const std::string &Character::getName() const {
    return (this->_name);
}

bool Character::isEquipped(AMateria *materia) {
    for (int i = 0; i < INVENTORY_SIZE; i++)
        if (_inventory[i] == materia)
            return (true);
    return (false);
}

void Character::equip(AMateria *m) {
    if (isEquipped(m)) {
        std::cout << BRED << "The materia is already equipped\n" << NC;
        return;
    }
    for (int i = 0; i < INVENTORY_SIZE; i++)
        if (!this->_inventory[i]) {
            this->_inventory[i] = m;
            std::cout << BRED << this->_name << " equipped: " << m->getType() << " in slot: " << i << NC << std::endl;
            return;
        }
    std::cout << BRED << "Cant equip materia: " << m->getType() << NC << std::endl;
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < INVENTORY_SIZE && this->_inventory[idx]) {
        std::cout   << BRED << this->getName() << " is unequiping: " << this->_inventory[idx]->getType()
                    << " materia from slot: " << idx << "\n" << NC;
        Node::addNode(&_matHead, Node::createNode(_inventory[idx]));
        this->_inventory[idx] = NULL;
    }
    else
        std::cout << BRED << this->_name <<  " cant't unequip slot: " << idx << NC << std::endl;
//    Node::print(&_matHead);
}

void Character::use(int idx, ICharacter &target) {
    if (idx < INVENTORY_SIZE && _inventory[idx])
        this->_inventory[idx]->use(target);
    else
        std::cout << BRED << "Can't use slot: " << idx << NC << std::endl;
}

