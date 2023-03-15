#include "Fixed.hpp"

int main( void ) {
    Fixed c(2);
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );


    std::cout << "=====Comparation overloads=====\n";
    std::cout << "A:" << a << " " << "B:" << b << std::endl;
    std::cout << (c > b) << std::endl;
    std::cout << (c < b) << std::endl;
    std::cout << (c >= b) << std::endl;
    std::cout << (c <= b) << std::endl;
    std::cout << (c == b) << std::endl;
    std::cout << (c != b) << std::endl;
    std::cout << "=====Arithmetic overloads=====\n";
    std::cout << "C:" << c << " " << "B:" << b << std::endl;
    std::cout << (c + b) << std::endl;
    std::cout << (c - b) << std::endl;
    std::cout << (c * b) << std::endl;
    std::cout << (c / b) << std::endl;
    std::cout << "=====Increment overloads=====\n";
    std::cout << "A:" << a << " " << "B:" << b << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;
    return 0;
}
