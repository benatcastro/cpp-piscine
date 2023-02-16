#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(const std::string weaponType) {
	this->setType(weaponType);
	std::cout << "Weapon constructor called" << std::endl;
}

Weapon::~Weapon(void) {
	std::cout << "Weapon destructor called" << std::endl;
}

void	Weapon::setType(const std::string _type) {
	this->type = _type;
}

const	std::string	&Weapon::getType(void) {
	return (this->type);
}
