#include "Point.hpp"

Fixed   computeArea(Point  A, Point  B, Point  C)
{
    Fixed area;
    Point semiP;
    Point half(2, 2);

    semiP = (A + B + C) / half;
    semiP.print();
    return (area);
}

int main( void ) {
    Point A(1, 1);
    Point B(2, 2);
    Point C(3, 3);

    computeArea(A, B, C);
    return(0);
}
