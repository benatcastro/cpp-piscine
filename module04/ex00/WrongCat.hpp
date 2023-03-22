#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
public:
    WrongCat(); // Default constructor
    WrongCat(WrongCat const &obj); // Copy constructor
    ~WrongCat(); // Default destructor
    WrongCat &operator=(WrongCat const &obj); // Assignment operator
    void    makeSound() const;
};

#endif
