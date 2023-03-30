#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
public:
    Ice(); // Default const
    Ice(Ice const &obj);
    Ice &operator=(Ice const &ojb); // Assignment operator
    ~Ice(); // Default dest

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);
};

#endif
