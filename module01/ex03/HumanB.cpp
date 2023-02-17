#include <iostream>
#include "HumanB.hpp"

HumanB::HumanB(const std::string _name): name(_name) {
	std::cout << "Human A constructor called" << std::endl;
}

HumanB::~HumanB(void) {
	std::cout << "Human A destructor called" << std::endl;
}

void HumanB::attack(void) {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

void HumanB::setWeapon(Weapon _weapon) {
	this->weapon = _weapon;
}
