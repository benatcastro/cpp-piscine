#ifndef FIXED_HPP
# define FIXED_HPP
# include <cmath>
# include <iostream>

class Fixed {
    public:
        Fixed(void);                        // Default constructor
        Fixed(const int n);                 // Integer overload
        Fixed(const float f);               // Float overload
        Fixed(const Fixed &obj);            // Copy constructor
        ~Fixed();                           // Destructor
        int     getFixedValue(void) const;
        float   toFloat(void) const;
        int     toInt(void) const;

        // Comparation overloads

        bool    Fixed::operator>(const Fixed &toCompare) const;
        bool    Fixed::operator<(const Fixed &toCompare) const;
        bool    Fixed::operator<=(const Fixed &lhs, const Fixed &rhs) const;
        bool    Fixed::operator>=(const Fixed &lhs, const Fixed &rhs) const;
        bool    Fixed::operator==(const Fixed &lhs, const Fixed &rhs) const;
        bool    Fixed::operator!=(const Fixed &lhs, const Fixed &rhs) const;

    private:
        int                 _fixedValue;
        static const int    _bits = 8;
};

std::ostream  &operator<<(std::ostream &os, const Fixed &obj);

#endif
