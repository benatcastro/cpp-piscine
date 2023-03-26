#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
public:
    Dog(); // Default constructor
    Dog(Dog const &obj); // Copy constructor
    virtual ~Dog(); // Default destructor
    Dog &operator=(Dog const &obj); // Assignment operator
    void    makeSound(void) const;
    void    getIdeas(void) const;
private:
   Brain    *brain;
};

#endif
