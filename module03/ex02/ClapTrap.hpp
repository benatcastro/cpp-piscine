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
    ClapTrap    &operator=(ClapTrap &obj); // Assignment overload
    void        attack(const std::string &target);
    void        takeDamage(unsigned int amount);
    void        beRepaired(unsigned int amount);
    bool        canUseAction(void);
//    std::string &getName(void);
//    u_int32_t   &getEnergyPoints(void);
//    u_int32_t   &getHitPoints(void);
//    u_int32_t   &getAttackDamage(void);
//    void        setName(std::string const name);
//    void        setEnergyPoints(u_int32_t ep);
//    void        setHitPoints(u_int32_t hp);
//    void        setAttackDamage(u_int32_t ad);

protected:
    std::string _name;
    u_int32_t _ep;
    u_int32_t _hp;
    u_int32_t _ad;
};

#endif
