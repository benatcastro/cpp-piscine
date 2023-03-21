#include "Scavtrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
    DiamondTrap d("Diamond2");
    ScavTrap scav;
    FragTrap frag;
    DiamondTrap a(d);

    d = a;
    d.print();
    scav.attack("Scav test");
    frag.attack("Frag test");
    d.ScavTrap::attack("Diamond test");
    d.whoAmI();
    d.takeDamage(100);
    d.whoAmI();
}
