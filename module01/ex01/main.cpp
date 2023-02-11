#include "Zombie.hpp"

int main(void) {
	Zombie *horde = zombieHorde(ZOMBIECOUNT, ZOMBIENAME);
	for (int i = 0; i < ZOMBIECOUNT; i++)
		horde[i].announce();
	delete [] horde;
}
