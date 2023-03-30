#include "AMateria.hpp"
#include <iostream>

// Default
AMateria::AMateria() {
    std::cout << "AMateria default constructor called\n";
}

// Copy
AMateria::AMateria(const AMateria &obj) {
    std::cout << "AMateria copy constructor called\n";
    this->_type = obj._type;

}

AMateria::~AMateria() {
    std::cout << "AMateria destructor called\n";
}

// Assignment
const AMateria &AMateria::operator=(const AMateria &obj) {
    this->_type = obj._type;
//    const AMateria tmp(obj);
    return (*this);
}

const std::string &AMateria::getType() const {
    return (this->_type);
}

void AMateria::use(ICharacter __unused &target) {}

AMateria::AMateria(const std::string &type): _type(type) {
    std::cout << "Amateria type constructor called\n";
}
