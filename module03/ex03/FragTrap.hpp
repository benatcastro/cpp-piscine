#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class FragTrap: virtual public ClapTrap {
public:
    FragTrap();
    FragTrap(int n, std::string const clapName);
    FragTrap(std::string const name);
    FragTrap(FragTrap &obj);
    ~FragTrap();
    void    print(void);

    FragTrap    &operator=(FragTrap &obj);
    void        highFiveGuys(void);
};

#endif
