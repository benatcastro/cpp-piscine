#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name): FragTrap(2, "Clap Default") {
    std::cout << "DiamondTrap default constructor called\n";
    this->_name = name;
    this->_hp = FragTrap::_hp;
    this->_ep = ScavTrap::_ep;
    this->_ad = FragTrap::_ad;
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap default destructor called\n";
    this->_name = "Diamond Default";
    this->_hp = FragTrap::_hp;
    this->_ep = ScavTrap::_ep;
    this->_ad = FragTrap::_ad;
}

DiamondTrap::DiamondTrap(DiamondTrap &obj) {
    std::cout << "DiamondTrap copy constructor called\n";
    (*this) = obj;
}

DiamondTrap DiamondTrap::operator=(const DiamondTrap &obj) {
    std::cout << "DiamondTrap assignment operator called\n";
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
    return (*this);
}

void DiamondTrap::print() {
    std::cout << "Name:" << this->_name << std::endl;
    std::cout << "AD:" << this->_ad << std::endl;
    std::cout << "EP:" << this->_ep << std::endl;
    std::cout << "HP:" << this->_hp << std::endl;
}

void DiamondTrap::whoAmI() {
    if (this->_hp < 1) {
        std::cout << "DiamondTrap: i'm dead\n";
        return;
    }
    std::cout << "DiamondTrap ClapName: " << ScavTrap::_name << "_clap_name " << "Name: " << this->_name << "\n";
}
