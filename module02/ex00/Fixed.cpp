#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() {
    std::cout << "Default constructor\n";
    this->_fixedValue = 0;
}

Fixed::Fixed(const Fixed &obj) {
    this->_fixedValue = obj._fixedValue;
}
Fixed   &Fixed::operator=(Fixed &obj) {

   this->_fixedValue = obj._fixedValue;
   return (*this);
}

Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called\n";
    return (this->_fixedValue);
}

void Fixed::setRawBits(const int raw) {
    this->_fixedValue = raw;
}
