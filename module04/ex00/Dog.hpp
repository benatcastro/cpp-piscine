#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
public:
    Dog(); // Default constructor
    Dog(Dog const &obj); // Copy constructor
    ~Dog(); // Default destructor
    Dog &operator=(Dog const &obj); // Assignment operator
    void    makeSound() const;
};

#endif
