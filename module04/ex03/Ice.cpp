#include "Ice.hpp"
#include <iostream>
#include "Defines.hpp"

Ice::Ice() {
    std::cout << "Ice materia constructed\n";
    this->_type = "ice";
}

Ice::Ice(const Ice &obj) {
    std::cout << "Ice copy constructor called\n";
    *this = obj;
}

Ice &Ice::operator=(const Ice &ojb) {
    this->_type = ojb._type;
    return (*this);
}

Ice::~Ice() {
    std::cout << "Ice materia destructed\n";
}

void Ice::use(__unused ICharacter &target) {
    std::cout << BCYAN << "* shoots an ice bolt at " << target.getName() << " *\n" << NC;
}

AMateria *Ice::clone() const {
    std::cout << "Cloning Ice\n";
    Ice *tmp = new Ice;
    return (tmp);
}

const std::string &Ice::getType() const {
    return (this->_type);
}
