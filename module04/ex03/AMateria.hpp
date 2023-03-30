#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>
#include "ICharacter.hpp"


class ICharacter;

class AMateria {
protected:
    std::string _type;
public:
    AMateria(std::string const & type); // Materia type constructor
    AMateria(); // Default Constructor
    virtual ~AMateria(); //     Default destructor
    AMateria(AMateria const &obj); // Copy constructor
    AMateria const &operator=(AMateria const &obj); // Assignment operator

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif
