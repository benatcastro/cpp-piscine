#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat default constructor called\n";
    this->brain = new Brain;
    this->type = "Cat";
}

Cat::Cat(const Cat &obj) {
    std::cout << "Cat copy constructor called\n";
    *this = obj;
}

Cat::~Cat() {
    if (this->brain)
        delete (this->brain);
    std::cout << "Cat default destructor called\n";
}

Cat &Cat::operator=(const Cat &obj) {
    std::cout << "Cat assignment operator called\n";
    this->type = obj.type;
    this->brain = new Brain(*obj.brain);
//    this->brain = obj.brain;
    return (*this);
}

void Cat::getIdeas() const {
    std::cout << this->type << " ideas -> ";
    this->brain->getIdeas();
}

void Cat::makeSound() const {
    std::cout << "Meowww...\n";
}
