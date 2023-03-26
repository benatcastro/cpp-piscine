#include "Animal.hpp"
#include <iostream>

Animal::Animal(): type("default animal") {
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const Animal &obj) {
    std::cout << "Animal copy constructor called\n";
    *this = obj;
}

Animal &Animal::operator=(const Animal &copy) {
    std::cout << "Animal assignment operator called\n";
    this->type = copy.type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal default destructor called\n";
}

const std::string &Animal::getType() {
    return (this->type);
}

const std::string &Animal::getType() const {
    return (this->type);
}

void Animal::makeSound() {
    std::cout << "Animal sounds...\n";
}

void Animal::getIdeas() const {}

void Animal::makeSound() const {
    std::cout << "Animal sounds...\n";
}
