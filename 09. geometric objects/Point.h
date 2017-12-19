#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <cmath>

class Point
{
private:
    double x;
    double y;

public:
    Point(double _x = 0, double _y = 0)
    : x(_x), y(_y)
    {}

    double getX() { return x; }
    double getY() { return y; }

    double distanceTo(Point other)
    {
        return sqrt((other.x - x)*(other.x - x) + (other.y - y)*(other.y - y));
    }
};

#endif // POINT_H_INCLUDED
