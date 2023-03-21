#include "ClapTrap.hpp"
#include "Scavtrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    ClapTrap bob;
    FragTrap frag("Frag");
    FragTrap frag2("frag2");
    ScavTrap francinette("Cagandou");

    frag = frag2;
    bob.attack("bob3");
    frag.attack("frag1");
    francinette.attack("baguette");
    frag.highFiveGuys();
    frag.takeDamage(100);
    frag.highFiveGuys();
}
