#include "Point.hpp"

Point::Point(): x(0), y(0) {
    std::cout << "Default point constructor called\n";
}

Point::Point(const float x, const float y): x(x), y(y) {
    std::cout << "Assignament point constructor called\n";
}

Point::Point(const Point &obj): x(obj.x), y(obj.y) {
    std::cout << "Point copy constructor called\n";
}

Point &Point::operator=(const Point &obj)
{
    (Fixed &)x = obj.x;
    (Fixed &)y = obj.y;
    return (*this);
}

Point::~Point() {
    std::cout << "Point destructor called\n";
}
