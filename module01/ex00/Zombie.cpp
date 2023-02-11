#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) {
	std::cout << "Zombie constructor called" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie destructor called for: " << this->name << std::endl;
}

void	Zombie::setName(const std::string _name) {
	this->name = _name;
}

void	Zombie::announce(void) {
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
