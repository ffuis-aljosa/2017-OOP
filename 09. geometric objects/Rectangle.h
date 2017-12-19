#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "GeometricObject.h"
#include "Point.h"

#include <stdexcept>

using namespace std;

class Rectangle : GeometricObject
{
private:
    Point upperLeftVertex;
    double width;
    double height;

public:
    Rectangle(string _name, Point _upperLeftVertex,
              double _width, double _height)
    : GeometricObject(_name), upperLeftVertex(_upperLeftVertex)
    {
        setWidth(_width);
        setHeight(_height);
    }

    void setWidth(double _width)
    {
        if (_width < 0)
            throw runtime_error("Sirina ne moze biti manja od 0");

        width = _width;
    }

    void setHeight(double _height)
    {
        if (_height < 0)
            throw runtime_error("Visina ne moze biti manja od 0");

        height = _height;
    }

    double area()
    {
        return width * height;
    }

    double circumference()
    {
        return 2 * (width + height);
    }

    Point getUpperLeftVertex()
    {
        return upperLeftVertex;
    }

    Point getLowerRightVertex()
    {
        return Point(upperLeftVertex.getX() + width, upperLeftVertex.getY() - height);
    }
};

#endif // RECTANGLE_H_INCLUDED
