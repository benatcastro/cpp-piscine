#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(const std::string _name, Weapon &_weapon): name(_name), weapon(_weapon) {
	std::cout << "Human A constructor called" << std::endl;
}

HumanA::~HumanA(void) {
	std::cout << "Human A destructor called" << std::endl;
}

void HumanA::attack(void) {
	std::cout <<  this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
