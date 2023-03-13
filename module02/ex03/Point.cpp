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

Point::~Point() {
    std::cout << "Point destructor called\n";
}

Point Point::operator+(const Point &value) {
    Point result(value);

    (Fixed &)result.x = (Fixed &)this->x + (Fixed &)result.x;
    (Fixed &)result.y = (Fixed &)this->y + (Fixed &)result.y;

    return (result);
}

Point Point::operator/(const Point &value) {
    Point result(value);

    (Fixed &)result.x = (Fixed &)this->x / (Fixed &)result.x;
    (Fixed &)result.y = (Fixed &)this->y / (Fixed &)result.y;

    return (result);
}

Point &Point::operator=(const Point &obj)
{
    (Fixed &)x = obj.x;
    (Fixed &)y = obj.y;

    return (*this);
}

void Point::print(void) {
    std::cout << "X:" << this->x <<  " | " <<  "Y:" << this->y << "\n";
}
