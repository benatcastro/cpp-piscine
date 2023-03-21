#include "ClapTrap.hpp"
#include "Scavtrap.hpp"

int main(void) {
    ClapTrap bob;
    ScavTrap francinette("Cagandou");
    ScavTrap francinette2(francinette);

    francinette = francinette2;

    bob.attack("bob");
    francinette.attack("frank");
    francinette.takeDamage(500);
    francinette.guardGate();
    francinette2.guardGate();
    bob.takeDamage(5);
}
