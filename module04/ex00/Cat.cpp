#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat default constructor called\n";
    this->type = "Cat";
}

Cat::Cat(const Cat &obj) {
    std::cout << "Cat copy constructor called\n";
    *this = obj;
}

Cat::~Cat() {
    std::cout << "Cat default destructor called\n";
}

Cat &Cat::operator=(const Cat &obj) {
    std::cout << "Cat assignment operator called\n";
    this->type = obj.type;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meowww...\n";
}
