#include "Cure.hpp"
#include <iostream>
#include "Defines.hpp"

Cure::Cure() {
    std::cout << "Cure materia constructed\n";
    this->_type = "cure";
}

Cure::Cure(const Cure &obj) {
    std::cout << "Cure copy constructor called\n";
    *this = obj;
}

Cure &Cure::operator=(const Cure &ojb) {
    this->_type = ojb._type;
    return (*this);
}

Cure::~Cure() {
    std::cout << "Cure materia destructed\n";
}

void Cure::use(ICharacter &target) {
    std::cout << BCYAN << "* heals " << target.getName() << " 's wounds *\n" << NC;
}

AMateria *Cure::clone() const {
    std::cout << "Cloning cure\n";
    Cure *tmp = new Cure;
    return (tmp);
}

const std::string &Cure::getType() const {
    return (this->_type);
}
