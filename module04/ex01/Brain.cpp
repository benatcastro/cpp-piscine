#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
    std::cout << "Brain constructor default called\n";
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = std::string("idea...");
}

Brain::Brain(const Brain &obj) {
    std::cout << "Bran copy constructor called\n";
    *this = obj;
}

Brain::~Brain() {
    std::cout << "Brain default destructor called\n";
}

const Brain &Brain::operator=(const Brain &obj) {
    std::cout << "Brain assignment operator called\n";
    for (int i = 0; i < 100; i++)
        if (this->_ideas[i] != obj._ideas[i])
            this->_ideas[i] = obj._ideas[i];
    return (*this);
}

void Brain::getIdeas() {
    for (int i = 0; i < 100; i++)
        std::cout << _ideas[i];
    std::cout << "\n";
}
