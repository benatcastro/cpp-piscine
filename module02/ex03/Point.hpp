#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
    public:
        Point(void);
        Point(float const x, float const y);
        Point(Point const &obj);
        ~Point(void);
        Fixed   getX(void) const;
        Fixed   getY(void) const;
        void    print(void);

        // Overloads

        Point   &operator=(Point const &obj);
        Point   operator+(Point const &value);
        Point   operator/(Point const &value);
    private:
        Fixed const x;
        Fixed const y;
};

bool    operator==(const Point &lhs, const Point &rhs);

#endif
