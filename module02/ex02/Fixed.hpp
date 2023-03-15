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
    int             getFixedValue(void) const;
    float           toFloat(void) const;
    int             toInt(void) const;
    static const Fixed    &min(Fixed &lhs, Fixed &rhs);
    static const Fixed    &min(Fixed const &lhs, Fixed const &rhs);
    static const Fixed    &max(Fixed &lhs, Fixed &rhs);
    static const Fixed    &max(Fixed const &lhs, Fixed const &rhs);

    // Arithmetic overloads

    Fixed    operator+(const Fixed &value);
    Fixed    operator-(const Fixed &value);
    Fixed    operator*(const Fixed &value);
    Fixed    operator/(const Fixed &value);

    // Increment overloads

    Fixed   operator++(int);
    Fixed   operator++();
    private:
    int                 _fixedValue;
    static const int    _bits = 8;
};

// Out operator
std::ostream    &operator<<(std::ostream &os, const Fixed &obj);

// < >  operators
bool            operator>(const Fixed &lhs, const Fixed &rhs);
bool            operator<(const Fixed &lhs, const Fixed &rhs);

// <= >= operators
bool            operator<=(const Fixed &lhs, const Fixed &rhs);
bool            operator>=(const Fixed &lhs, const Fixed &rhs);

// == != operators
bool            operator!=(const Fixed &lhs, const Fixed &rhs);
bool            operator==(const Fixed &lhs, const Fixed &rhs);
#endif
