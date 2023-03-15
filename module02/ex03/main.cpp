#include "Point.hpp"


Fixed computeSlope(Point v1, Point v2) {
    Point min, max;
    Fixed slope;


    if (v1 >= v2) {
        max = v1;
        min = v2;
    }
    else {
        max = v2;
        min = v1;
    }

    return (slope);
}

Fixed computeArea(Point a, Point b, Point c) {
    Fixed   semiP;

    semiP = (a.getX() * (b.getY() - c.getY()))
            + (b.getX() * (c.getY() - a.getY()))
            + (c.getX() * (a.getY() - b.getY()));
    if ((semiP / 2) > 0)
        return (semiP / 2);
    return ((semiP / 2) * -1);
}

bool betweenVectors(Point v1, Point v2, Point point) {
    Point min, max;

    if (computeSlope(v1, v2) == computeSlope(v1, point))
    {
        if (v1 >= v2) {
            max = v1;
            min = v2;
        }
        else {
            max = v2;
            min = v1;
        }
        if (point <= max && point >= min)
            return (true);
    }
    return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed aSum;
    bool inEdges, inVectors;

    aSum = computeArea(a, b, point) + computeArea(b, c, point) + computeArea(a, c, point);
    inEdges = betweenVectors(a, b, point) || betweenVectors(a, c, point) || betweenVectors(c, b, point);
    inVectors = point == a || point == b || point == c;
//    std::cout << "Area condition:" << (aSum > computeArea(a, b, c)) << std::endl;
//    std::cout << "Edge condition:" << inEdges << std::endl;
//    std::cout << "Vector condition:" << inVectors << std::endl;
    if (aSum > computeArea(a, b, c) || inEdges || inVectors)
        return (false);
    return (true);
}


int main( void ) {
    Point a(5, 3);
    Point b(5, 10);
    Point c(1,-1);
    Point point(5,4);

    std::cout << "Point lies inside the triangle:" << bsp(a, b, c, point) << "\n";

    return(0);
}
