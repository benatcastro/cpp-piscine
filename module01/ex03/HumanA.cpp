#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string weaponType, Weapon &weapon) {
	this->weapon = weapon;
	this->weapon.setType(weaponType);
	std::cout << "Human A constructor called" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "Human A destructor called" << std::endl;
}

