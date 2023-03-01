#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
    std::cout << "Default constructor" << std::endl;
    this->fixedValue = 0;
}

Fixed::Fixed(const Fixed &obj) {
    
}