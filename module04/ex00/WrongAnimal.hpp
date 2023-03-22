#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <string>

class WrongAnimal {

public:
    WrongAnimal(); // Default constructor
    WrongAnimal(WrongAnimal const &obj); // Copy constructor
    ~WrongAnimal(); // Default destructor
    WrongAnimal &operator=(WrongAnimal const &copy);
    std::string const &getType();
    std::string const &getType() const;
    void    makeSound(void);
    void    makeSound(void) const;

protected:
    std::string type;

};
#endif
