#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap: virtual public ClapTrap {
public:
    ScavTrap();
    ScavTrap(std::string const name);
    ScavTrap(ScavTrap &obj);
    ~ScavTrap();
    ScavTrap    &operator=(ScavTrap &obj);
    void        guardGate(void);
    void        attack(const std::string &target);
    bool        canUseAction(void);
};

#endif
