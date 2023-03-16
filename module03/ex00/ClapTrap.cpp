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

ClapTrap &ClapTrap::operator=(const ClapTrap &obj) {
    std::cout << "ClapTrap assignment operator called\n";
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
    return (*this);
}
