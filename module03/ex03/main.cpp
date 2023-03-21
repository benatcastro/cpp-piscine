#include "Scavtrap.hpp"
#include "DiamondTrap.hpp"

int main(void) {
        DiamondTrap d("Diamond");
//    ClapTrap *d = DiamondTrap("Diamond");
    d.print();
    d.ScavTrap::attack("Test");
    d.whoAmI();
}
