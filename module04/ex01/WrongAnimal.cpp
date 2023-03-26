#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("default wrong animal") {
    std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj) {
    std::cout << "WrongAnimal copy constructor called\n";
    *this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &copy) {
    std::cout << "WrongAnimal assignment operator called\n";
    this->type = copy.type;
    return (*this);
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal default destructor called\n";
}

const std::string &WrongAnimal::getType() {
    return (this->type);
}

const std::string &WrongAnimal::getType() const {
    return (this->type);
}

void WrongAnimal::makeSound() {
    std::cout << "Wrong Animal sounds...\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "Wrong Animal sounds...\n";
}
