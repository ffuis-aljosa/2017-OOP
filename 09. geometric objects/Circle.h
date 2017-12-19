#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "GeometricObject.h"
#include "Point.h"

#include <stdexcept>

using namespace std;

class Circle : GeometricObject
{
private:
    Point center;
    double radius;

public:
    Circle(string _name, Point _center = Point(), double _r = 1)
    : GeometricObject(_name), center(_center)
    {
        setRadius(_r);
    }

    void setRadius(double _r)
    {
        if (_r < 0)
            throw runtime_error("Poluprecnik ne moze biti manji od 0");

        radius = _r;
    }

    double area()
    {
        return radius * radius * 3.14;
    }

    double circumference()
    {
        return 2 * radius * 3.14;
    }
};

#endif // CIRCLE_H_INCLUDED
