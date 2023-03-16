#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#define ENERGY_COST 1

class ClapTrap {
public:
    ClapTrap(); // Default constructor
    ClapTrap(ClapTrap &obj); // Copy constructor
    ~ClapTrap();
    ClapTrap    &operator=(ClapTrap const &obj); // Assignment overload
    void        attack(const std::string &target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
private:
    std::string _name;
    u_int32_t _ep;
    u_int32_t _hp;
    u_int32_t _ad;
};

#endif
