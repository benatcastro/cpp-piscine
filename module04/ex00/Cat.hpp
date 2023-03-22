#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
public:
    Cat(); // Default constructor
    Cat(Cat const &obj); // Copy constructor
    ~Cat(); // Default destructor
    Cat &operator=(Cat const &obj); // Assignment operator
    void    makeSound() const;
};

#endif
