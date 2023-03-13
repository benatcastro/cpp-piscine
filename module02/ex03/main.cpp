#include "Point.hpp"

Fixed computeArea(Point a, Point b, Point c) {
    Fixed   semiP;

    semiP = (a.getX() * (b.getY() - c.getY()))
            + (b.getX() * (c.getY() - a.getY()))
            + (c.getX() * (a.getY() - b.getY()));
    if ((semiP / 2) > 0)
        return (semiP / 2);
    return ((semiP / 2) * -1);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed aSum;

    aSum = computeArea(a, b, point) + computeArea(b, c, point) + computeArea(a, c, point);
    std::cout << "asum:" << aSum << "\n";
    if (aSum > computeArea(a, b, c))
        return (false);
    return (true);
}


int main( void ) {
    Point a(5, 3);
    Point b(0, 10);
    Point c(1,-1);
    Point point(1,1);

    std::cout << bsp(a, b, c, point) << "\n";

    return(0);
}
