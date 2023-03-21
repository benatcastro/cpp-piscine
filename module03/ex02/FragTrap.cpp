#include "FragTrap.hpp"

FragTrap::FragTrap() {
    std::cout << "FragTrap default constructor called\n";
    this->_name = "Frag default";
    this->_hp = 100;
    this->_ep = 100;
    this->_ad = 30;

}

FragTrap::FragTrap(std::string const name) {
    std::cout << "FragTrap default constructor called\n";
    this->_name = name;
    this->_hp = 100;
    this->_ep = 100;
    this->_ad = 30;
}

FragTrap::FragTrap(FragTrap &obj) {
    std::cout << "FragTrap copy constructor called\n";
    *this = obj;
}

FragTrap& FragTrap::operator=(FragTrap &obj) {
    std::cout << "FragTrap assignment operator called\n";
    this->_name = obj._name;
    this->_hp = obj._hp;
    this->_ep = obj._ep;
    this->_ad = obj._ad;
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap default destructor called\n";
}

void FragTrap::highFiveGuys() {
    if (this->_hp < 1) {
        std::cout << "FragTrap " << this->_name << " is dead, he can't high five!\n";
        return;
    }
    if (this->_ep < 1) {
        std::cout << "FragTrap " << this->_name << " is too tired, he can't high five!\n";
        return;
    }
    std::cout << "FragTrap " << this->_name << " requests a high five!\n";
}
