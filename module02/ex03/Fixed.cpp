#include "Fixed.hpp"

Fixed::Fixed() {
//    std::cout << "Default constructor\n";
    this->_fixedValue = 0;
}

Fixed::Fixed(const int n): _fixedValue(n << 8) {
//    std::cout << "Int constructor\n";
}

Fixed::Fixed(const float f): _fixedValue(roundf(f * (1 << 8))) {
//    std::cout << "Float constructor\n";
}
Fixed::Fixed(const Fixed &obj) {
//    std::cout << "Copy constructor called\n";
    this->_fixedValue = obj._fixedValue;
}

int Fixed::getFixedValue() const {
    return (this->_fixedValue);
}
Fixed::~Fixed() {
//    std::cout << "Destructor called\n";
}

int Fixed::toInt(void) const {
    return (this->_fixedValue >> this->_bits);
}

float Fixed::toFloat(void) const {
    return ((float)this->_fixedValue / (1 << this->_bits));
}

// Assignament operator
void Fixed::operator=(Fixed const &fixed) {
    this->_fixedValue = fixed.getFixedValue();
}
// Compare operators

bool    operator>(const Fixed &lhs, const Fixed &rhs) {
//    std::cout << "operator: (" << lhs.getFixedValue() << " > " << rhs.getFixedValue() << ")\n";

    return (lhs.getFixedValue() > rhs.getFixedValue());
}

bool    operator<(const Fixed &lhs, const Fixed &rhs) {
//    std::cout << "operator: (" << lhs.getFixedValue() << " < " << rhs.getFixedValue() << ")\n";

    return (lhs.getFixedValue() < rhs.getFixedValue());
}

bool    operator>=(const Fixed &lhs, const Fixed &rhs) {
//    std::cout << "operator: (" << lhs.getFixedValue() << " >= " << rhs.getFixedValue() << ")\n";

    return (lhs.getFixedValue() == rhs.getFixedValue() || lhs.getFixedValue() > rhs.getFixedValue());
}

bool    operator<=(const Fixed &lhs, const Fixed &rhs) {
//    std::cout << "operator: (" << lhs.getFixedValue() << " <= " << rhs.getFixedValue() << ")\n";

    return (lhs.getFixedValue() == rhs.getFixedValue() || lhs.getFixedValue() < rhs.getFixedValue());
}

bool    operator==(const Fixed &lhs, const Fixed &rhs) {
//    std::cout << "operator: (" << lhs.getFixedValue() << " == " << rhs.getFixedValue() << ")\n";

    return (lhs.getFixedValue() == rhs.getFixedValue());
}

bool    operator!=(const Fixed &lhs, const Fixed &rhs) {
//    std::cout << "operator: (" << lhs.getFixedValue() << " != " << rhs.getFixedValue() << ")\n";

    return (lhs.getFixedValue() != rhs.getFixedValue());
}

// Arithmetic operators

Fixed    Fixed::operator+(const Fixed &value) {
//    std::cout << "operator: (" << this->getFixedValue() << " + " << value.getFixedValue() << ")\n";
    Fixed result(this->toFloat() + value.toFloat());

    return (result);
}

Fixed    Fixed::operator-(const Fixed &value) {
//    std::cout << "operator: (" << this->getFixedValue() << " - " << value.getFixedValue() << ")\n";
    Fixed result(this->toFloat() - value.toFloat());

    return (result);
}

Fixed    Fixed::operator*(const Fixed &value) {
//    std::cout << "operator: (" << this->getFixedValue() << " * " << value.getFixedValue() << ")\n";
    Fixed result(this->toFloat() * value.toFloat());

    return (result);
}

Fixed    Fixed::operator/(const Fixed &value) {
//    std::cout << "operator: (" << this->getFixedValue() << " / " << value.getFixedValue() << ")\n";
    Fixed result(this->toFloat() / value.toFloat());

    return (result);
}

Fixed Fixed::operator++() {
    std::cout << "operator: (++pre) called\n";

    return (++this->_fixedValue);
}

Fixed Fixed::operator++(int) {
    std::cout << "operator: (post++) called\n";

    return (this->_fixedValue++);
}

std::ostream  &operator<<(std::ostream &os, const Fixed &obj) {
    os << obj.toFloat();
    return (os);
}

