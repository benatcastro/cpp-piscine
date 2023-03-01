#include "Fixed.hpp"

int main( void ) {
    Fixed a(5);
    Fixed b(10);
    std::cout << a << std::endl;
    std::cout << a.operator!=(a, b);
//    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
//    std::cout << a << std::endl;
//    std::cout << ++a << std::endl;
//    std::cout << a << std::endl;
//    std::cout << a++ << std::endl;
//    std::cout << a << std::endl;
//    std::cout << b << std::endl;
//    std::cout << Fixed::max( a, b ) << std::endl;
    return
}