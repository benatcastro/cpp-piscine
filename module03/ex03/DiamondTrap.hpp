#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "Scavtrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap: virtual public ScavTrap, virtual public FragTrap {
public:
    DiamondTrap(std::string const name);
    DiamondTrap(DiamondTrap &obj);
    ~DiamondTrap();
    DiamondTrap operator=(DiamondTrap const &obj);
    using ScavTrap::attack;
    void    whoAmI(void);
    void    print(void);

private:
    std::string _name;
};

#endif
