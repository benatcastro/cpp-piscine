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
    return ((max.getY() - min.getY()) / (max.getX() - min.getX()));
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
    bool isBetween = false;

    if (computeSlope(v1, v2) == computeSlope(v1, point)
        && computeSlope(v1, v2) == computeSlope(v2, point))
    {
        if (v1 >= v2) {
            max = v1;
            min = v2;
        }
        else {
            max = v2;
            min = v1;
        }
//        std::cout << "max: "; max.print();
//        std::cout << "min: "; min.print();
//        std::cout << "point: "; point.print();
        isBetween = (point <= max && point >= min);
    }
    return (isBetween);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed aSum;
    bool inEdges, inVectors;

//    std::cout << std::endl;
//    std::cout << betweenVectors(a, b, point) << std::endl;
//    std::cout << betweenVectors(a, c, point) << std::endl;
//    std::cout << betweenVectors(c, b, point) << std::endl;
    aSum = computeArea(a, b, point) + computeArea(b, c, point) + computeArea(a, c, point);
    inEdges = betweenVectors(a, b, point) || betweenVectors(a, c, point) || betweenVectors(c, b, point);
    inVectors = (point == a || point == b || point == c);
    std::cout << "Area condition:" << !(aSum == computeArea(a, b, c)) << std::endl;
    std::cout << "Edge condition:" << inEdges << std::endl;
    std::cout << "Vector condition:" << inVectors << std::endl;
//    std::cout << aSum << std::endl;
//    std::cout << computeArea(a, b, c) << std::endl;
    return !(!(aSum == computeArea(a, b, c)) || inEdges || inVectors);
}


int main( void ) {
    Point a(0, 0);
    Point b(10, 0);
    Point c(5,5);
    Point point(7,4);

    std::cout << "Point lies inside the triangle:" << bsp(a, b, c, point) << "\n";

    return(0);
}
