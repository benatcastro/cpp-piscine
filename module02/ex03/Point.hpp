#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        Point(void);
        Point(float const x, float const y);
        Point(Point const &obj);
//        Point   &operator=(Point const &obj);
        ~Point(void);
    private:
        Fixed const x;
        Fixed const y;
};
#endif
