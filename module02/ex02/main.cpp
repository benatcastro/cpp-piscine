#include "Fixed.hpp"

int main( void ) {
    Fixed a(2);
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << (a > b) << std::endl;
    std::cout << (a < b) << std::endl;
    std::cout << (a >= b) << std::endl;
    std::cout << (a <= b) << std::endl;
    std::cout << (a == b) << std::endl;
    std::cout << (a != b) << std::endl;
    std::cout << (a + b) << std::endl;
    std::cout << (a - b) << std::endl;
    std::cout << (a * b) << std::endl;
    std::cout << (a / b) << std::endl;

    std::cout << "Result: " << b << std::endl;
    std::cout << "Result:" << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "Result:" <<a << std::endl;
    std::cout <<  a++ << std::endl;
    std::cout << "Result:" << a << std::endl;
    std::cout << "Result:" << b << std::endl;
//    std::cout << Fixed::max( a, b ) << std::endl;
    return(0);
}
