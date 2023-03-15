#include "Point.hpp"

Point::Point(): x(0), y(0) {
}

Point::Point(const float x, const float y): x(x), y(y) {
}

Point::Point(const Point &obj): x(obj.x), y(obj.y) {
}

Point::~Point() {
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

bool    operator==(const Point &lhs, const Point &rhs) {

   return (lhs.getX() == rhs.getX() && lhs.getY() == rhs.getY());
}

void Point::print(void) {
    std::cout << "X:" << this->x <<  " | " <<  "Y:" << this->y << "\n";
}

Fixed Point::getX() const {
    return (this->x);
}

Fixed Point::getY() const {
    return (this->y);
}
