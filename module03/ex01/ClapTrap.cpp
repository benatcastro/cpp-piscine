#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Bob"), _ep(10), _hp(10), _ad(0) {
    std::cout << "ClapTrap default constructor called\n";
}

ClapTrap::ClapTrap(ClapTrap &obj) {
    std::cout << "ClapTrap copy constructor called\n";
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called\n";
}

ClapTrap &ClapTrap::operator=(ClapTrap &obj) {
    std::cout << "ClapTrap assignment operator called\n";
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
    return (*this);
}

//void ClapTrap::setName(const std::string name) {
//    this->_name = name;
//}
//
//void ClapTrap::setAttackDamage(u_int32_t ad) {
//    this->_ad = ad;
//}
//
//void ClapTrap::setEnergyPoints(u_int32_t ep) {
//    this->_ep = ep;
//}
//
//void ClapTrap::setHitPoints(u_int32_t hp) {
//    this->_hp = hp;
//}
//
//std::string &ClapTrap::getName() {
//    return (this->_name);
//}
//
//u_int32_t &ClapTrap::getAttackDamage() {
//    return (this->_ad);
//}
//
//u_int32_t &ClapTrap::getEnergyPoints() {
//    return (this->_ep);
//}
//
//u_int32_t &ClapTrap::getHitPoints() {
//    return (this->_hp);
//}

bool ClapTrap::canUseAction() {
    bool useAction = true;

    if (this->_ep < 1) {
        std::cout << "ClapTrap " << this->_name << " doesn't have enough energy points!\n";
        useAction = false;
    }
    if (this->_hp < 1) {
        std::cout << "ClapTrap " << this->_name << " is dead!\n";
        useAction = false;
    }
    return (useAction);
}

void ClapTrap::attack(const std::string &target) {
    if (!this->canUseAction()) return;
    this->_ep--;
    std::cout << "ClapTrap attacks " << target << ", causing " << this->_ad << " points of damage!\n";
    return ;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hp < 1) {
        std::cout << "ClapTrap " << this->_name << " is already dead!\n";
        return;
    }
    if (amount > this->_hp)
        this->_hp = amount;
    if (amount >= this->_hp) {
        std::cout << "ClapTrap receives " << amount << ", points of damage and dies!\n";
        this->_hp -= amount;
        return;
    }
    std::cout << "ClapTrap receives " << amount << ", points of damage!\n";
    this->_hp -= amount;
    return;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (!this->canUseAction()) return;
    this->_ep--;
    std::cout << "ClapTrap gets repaired by " << amount << ", hit points now having "
    << this->_hp + amount << " energy points!\n";
    this->_hp += amount;
}
