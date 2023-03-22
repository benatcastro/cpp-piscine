#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() {
    std::cout << "WrongCat default constructor called\n";
    this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &obj) {
    std::cout << "WrongCat copy constructor called\n";
    *this = obj;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat default destructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &obj) {
    std::cout << "WrongCat assignment operator called\n";
    this->type = obj.type;
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Meowww... but it's wrong\n";
}
