#include "Cure.hpp"
#include <iostream>

Cure::Cure() {
    std::cout << "Cure materia constructed\n";
    this->_type = "cure";
}

Cure::Cure(__unused const Cure &obj) {
std::cout << "Cure copy constructor called\n";
// Todo
}

Cure &Cure::operator=(__unused const Cure &ojb) {
// todo waiting for further declarations
return (*this);
}

Cure::~Cure() {
    std::cout << "Cure materia destructed\n";
}

void Cure::use(ICharacter &target) {
    std::cout << "* heals " << target.getName() << " 's wounds *\n";
}

AMateria *Cure::clone() const {
    std::cout << "Cloning cure\n";
    Cure *tmp = new Cure;
    return (tmp);
}

const std::string &Cure::getType() const {
    return (this->_type);
}
