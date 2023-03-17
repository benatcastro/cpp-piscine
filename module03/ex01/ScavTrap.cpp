#include "Scavtrap.hpp"

ScavTrap::ScavTrap(const std::string name) {
    std::cout << "ScavTrap default constructor called\n";
    this->_name = name;
    this->_hp = 100;
    this->_ep = 50;
    this->_ad = 20;
}

ScavTrap::ScavTrap(ScavTrap &obj) {
    std::cout << "ScavTrap copy constructor called\n";
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
}

ScavTrap &ScavTrap::operator=(ScavTrap &obj) {
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap default destructor called\n";
}

void ScavTrap::guardGate() {
    if (this->_hp < 1) {
        std::cout << "ScavTrap " << this->_name << " is dead and can't guard the gate!\n";
        return;
    }
    std::cout << "ScavTrap " << this->_name << " is guarding the gate!\n";

}

bool ScavTrap::canUseAction() {
    bool useAction = true;

    if (this->_ep < 1) {
        std::cout << "ScavTrap " << this->_name << " doesn't have enough energy points!\n";
        useAction = false;
    }
    if (this->_hp < 1) {
        std::cout << "ScavTrap " << this->_name << " is dead!\n";
        useAction = false;
    }
    return (useAction);
}

void ScavTrap::attack(const std::string &target) {
    if (!this->canUseAction()) return;
    this->_ep--;
    std::cout << "ScavTrap " << this->_name << " uses his robotic arms to attack " << target << ", causing " << this->_ad << " points of damage!\n";
    return ;

}
