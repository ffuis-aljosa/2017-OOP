#ifndef GEOMETRICOBJECT_H_INCLUDED
#define GEOMETRICOBJECT_H_INCLUDED

#include <stdexcept>

using namespace std;

class GeometricObject
{
protected:
    string name;

public:
    GeometricObject(string _name)
    {
        setName(_name);
    }

    void setName(string _name)
    {
        if (_name == "")
            throw runtime_error("Naziv objekta ne moze biti prazan");

        name = _name;
    }

    virtual double area() = 0;
    virtual double circumference() = 0;
};

#endif // GEOMETRICOBJECT_H_INCLUDED
