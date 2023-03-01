#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor\n";
    this->_fixedValue = 0;
}

Fixed::Fixed(const int n): _fixedValue(n << 8) {
    std::cout << "Int constructor\n";
}

Fixed::Fixed(const float f): _fixedValue(roundf(f * (1 << 8))) {
    std::cout << "Float constructor\n";
}
Fixed::Fixed(const Fixed &obj) {
    std::cout << "Copy constructor called\n";
    this->_fixedValue = obj._fixedValue;
}

int Fixed::getFixedValue() const {
    return (this->_fixedValue);
}
Fixed::~Fixed() {
    std::cout << "Destructor called\n";
}

int Fixed::toInt(void) const {
    return (this->_fixedValue >> this->_bits);
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixedValue / (1 << this->_bits));
}

// Operators

bool    Fixed::operator>(const Fixed &toCompare) const {
    std::cout << "> called\n";
    return (this->_fixedValue > toCompare._fixedValue);
}

bool    Fixed::operator<(const Fixed &toCompare) const {
    std::cout << "< called\n";
    return (this->_fixedValue < toCompare._fixedValue);
}

bool    Fixed::operator>=(const Fixed &lhs, const Fixed &rhs) const {
    std::cout << ">= called\n";
    return (lhs == rhs || rhs > lhs);
}

bool    Fixed::operator<=(const Fixed &lhs, const Fixed &rhs) const {
    std::cout << "<= called\n";
    return (lhs == rhs || rhs < lhs);
}

bool    Fixed::operator==(const Fixed &lhs, const Fixed &rhs) const {
    std::cout << "== called\n";
    return (lhs == rhs);
}

bool    Fixed::operator!=(const Fixed &lhs, const Fixed &rhs) const {
    std::cout << "!= called\n";
    return !(lhs == rhs);
}


std::ostream  &operator<<(std::ostream &os, const Fixed &obj) {
    os << obj.toFloat();
    return (os);
}

