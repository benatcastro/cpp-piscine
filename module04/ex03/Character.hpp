#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include <string>
#include "Defines.hpp"
#include "Node.hpp"

class Character: public ICharacter {
private:
    std::string const _name;
    AMateria    *_inventory[INVENTORY_SIZE];
    struct Node *_matHead;

public:
    Character(); // Default constructor
    Character(std::string const &name); // Name constructor
    Character(Character const &obj); // Copy constructor
    ~Character(); // Default constructor
    Character &operator=(const Character &obj);
    std::string const & getName() const;
    void equip(AMateria* m) ;
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    bool isEquipped(AMateria *materia);

};
#endif
