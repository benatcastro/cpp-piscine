#include "ClapTrap.hpp"

int main(void) {
    ClapTrap bob;

    bob.beRepaired(10);
    bob.attack("Norminette");
    bob.takeDamage(15);
    bob.attack("Moulinette");
    bob.takeDamage(0);
    bob.takeDamage(15);
    bob.beRepaired(10);
    bob.attack("Baguette");
}
