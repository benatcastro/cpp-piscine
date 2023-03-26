#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
public:
    Cat(); // Default constructor
    Cat(Cat const &obj); // Copy constructor
    virtual ~Cat(); // Default destructor
    Cat &operator=(Cat const &obj); // Assignment operator
    void    makeSound() const;
    void    getIdeas(void) const;
private:
        Brain   *brain;
};

#endif
