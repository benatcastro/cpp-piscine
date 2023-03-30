#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#define  TEST 42
class Cure: public AMateria {
public:
    Cure(); // Default const
    Cure(Cure const &obj);
    Cure &operator=(Cure const &obj); // Assignment operator
    ~Cure(); // Default dest

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};
#endif
