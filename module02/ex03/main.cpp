#include "Point.hpp"

bool fixedRange(Fixed const f, Fixed const min, Fixed const max) {
    if (f > min && f < max)
        return (true);
    return (false);
}

Fixed det(Point const a, Point const b){
    return ((a.getX() * b.getY()) - (a.getY() * b.getX()));
}

Fixed convexPoint(Point const a, Point const b, Point const c, Point const point)
{
    return ((det(point, c) - det(a, c)) / det(b, c));
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed convexA = convexPoint(a, b, c, point);
    Fixed convexB = convexPoint(b, c, a, point);
    Fixed convexC = convexPoint(c, b, a, point);

    if (fixedRange(convexA, 0, 1)
        && fixedRange(convexB, 0, 1)
        && fixedRange(convexC, 0, 1))
        return (true);
    return (false);
}


int main( void ) {
    Point a(5, 3);
    Point b(0, 10);
    Point c(1,-1);
    Point point(2,4);

    std::cout << bsp(a, b, c, point) << "\n";

    return(0);
}
