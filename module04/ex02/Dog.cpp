#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog default constructor called\n";
    this->type = "Dog";
    this->brain = new Brain;
}

Dog::Dog(const Dog &obj) {
    std::cout << "Dog copy constructor called\n";
    this->brain = new Brain(*obj.brain);
//    delete this->brain;
//    delete this->brain;

    *this = obj;
}

Dog::~Dog() {
    std::cout << "Dog default destructor called\n";
    delete this->brain;
}

Dog &Dog::operator=(const Dog &obj) {
    std::cout << "Dog assignment operator called\n";
    this->type = obj.type;
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Bark bark...\n";
}

void Dog::getIdeas() const {
    std::cout << this->type << " ideas -> ";
    this->brain->getIdeas();
}
