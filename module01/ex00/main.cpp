#include "Zombie.hpp"

int main(void) {
	Zombie	*zombiePtr;

	zombiePtr = newZombie("Heap");
	randomChump("Stack");
	delete zombiePtr;
}
