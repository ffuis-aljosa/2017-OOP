#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "GeometricObject.h"
#include "Point.h"

using namespace std;

class Triangle : GeometricObject
{
private:
    Point vertexA;
    Point vertexB;
    Point vertexC;

public:
    Triangle(string _name, Point _vertexA, Point _vertexB, Point _vertexC)
    : GeometricObject(_name), vertexA(_vertexA),
      vertexB(_vertexB), vertexC(_vertexC)
    {}

    double sideA()
    {
        return vertexB.distanceTo(vertexC);
    }

    double sideB()
    {
        return vertexA.distanceTo(vertexC);
    }

    double sideC()
    {
        return vertexA.distanceTo(vertexB);
    }

    double circumference()
    {
        return sideA() + sideB() + sideC();
    }

    double area()
    {
        double s = circumference() / 2;

        return sqrt(s * (s - sideA()) * (s - sideB()) * (s - sideC()));
    }
};

#endif // TRIANGLE_H_INCLUDED
