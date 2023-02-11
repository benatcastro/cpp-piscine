#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie	*newZombie(std::string name) {
	Zombie	*zombiePtr = new Zombie;

	zombiePtr->setName(name);
	return zombiePtr;
}
