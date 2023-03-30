#include "Ice.hpp"
#include <iostream>

Ice::Ice() {
    std::cout << "Ice materia constructed\n";
    this->_type = "ice";
}

Ice::Ice(__unused const Ice &obj) {
    std::cout << "Ice copy constructor called\n";
}

Ice &Ice::operator=(const Ice &ojb) {
    // todo waiting for further declarations
    Ice *tmp = new Ice(ojb);
    return (*tmp);
}

Ice::~Ice() {
    std::cout << "Ice materia destructed\n";
}

void Ice::use(__unused ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

AMateria *Ice::clone() const {
    std::cout << "Cloning Ice\n";
    Ice *tmp = new Ice;
    return (tmp);
}

const std::string &Ice::getType() const {
    return (this->_type);
}
