#include "ClapTrap.hpp"

int main(void) {
    ClapTrap bob;
    ClapTrap bob2(bob);
    ClapTrap bob3;

    bob = bob2;
    bob.beRepaired(10);
    bob.attack("Norminette");
    bob.takeDamage(15);
    bob.attack("Moulinette");
    bob.takeDamage(0);
    bob.takeDamage(15);
    bob.beRepaired(10);
    for (int i = 0; i < 11; i++)
        bob3.attack("test");
    bob.attack("Baguette");
}
