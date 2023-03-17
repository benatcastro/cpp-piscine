#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap: public ClapTrap {
public:
    FragTrap(std::string const name);
    FragTrap(FragTrap &obj);
    ~FragTrap();

    FragTrap    &operator=(FragTrap &obj);
    void        highFiveGuys(void);
};

#endif
