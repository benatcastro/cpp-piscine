#include "Zombie.hpp"
#include <iostream>

void	randomChump(std::string name) {
	Zombie zombie;

	zombie.setName(name);
	zombie.announce();
}
