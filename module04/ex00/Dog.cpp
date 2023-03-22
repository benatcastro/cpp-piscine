#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    this->type = "Dog";
}

Dog::Dog(const Dog &obj) {
    std::cout << "Dog copy constructor called\n";
    *this = obj;
}

Dog::~Dog() {
    std::cout << "Dog default destructor called\n";
}

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Dog assignment operator called\n";
    this->type = obj.type;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Bark bark...\n";
}
