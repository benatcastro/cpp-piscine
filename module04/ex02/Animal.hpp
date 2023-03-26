#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal {

public:
    Animal(); // Default constructor
    Animal(Animal const &obj); // Copy constructor
    virtual ~Animal(); // Default destructor
    Animal &operator=(Animal const &copy);
    std::string const &getType();
    std::string const &getType() const;
    virtual void    makeSound(void) const = 0;
    virtual void    getIdeas(void) const;

protected:
    std::string type;

};
#endif
