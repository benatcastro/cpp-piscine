#include "ClapTrap.hpp"
#include "Scavtrap.hpp"

int main(void) {
    ClapTrap bob;
    ScavTrap francinette("Cagandou");
    ScavTrap francinette2("Moulinette");

    bob.attack("bob's target");
    francinette.attack("franks's target");
    francinette.takeDamage(500);
    francinette.guardGate();
    francinette2.guardGate();
    bob.takeDamage(5);
}
