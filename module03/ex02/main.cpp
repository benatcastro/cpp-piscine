#include "ClapTrap.hpp"
#include "Scavtrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ClapTrap bob;
    FragTrap frag("Frag");
    ScavTrap francinette("Cagandou");

    bob.attack("bob3");
    frag.highFiveGuys();
    frag.attack("frag1");
    francinette.attack("baguette");
    frag.takeDamage(99);
    frag.highFiveGuys();
}
