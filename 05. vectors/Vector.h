#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <stdexcept>

using namespace std;

class Vector
{
private:
    int dimension;
    double* values;

public:
    Vector()
    : dimension(0), values(NULL)
    {}

    Vector(const Vector& vector)
    {
        dimension = vector.dimension;

        values = new double[dimension];

        for (int i = 0; i < dimension; i++)
            values[i] = vector.values[i];
    }

    Vector& operator = (const Vector& vector)
    {
        delete [] values;

        dimension = vector.dimension;

        values = new double[dimension];

        for (int i = 0; i < dimension; i++)
            values[i] = vector.values[i];

        return *this;
    }

    Vector(double* _values, int _dimension)
    : dimension(_dimension)
    {
        values = new double[dimension];

        for (int i = 0; i < dimension; i++)
            values[i] = _values[i];
    }

    Vector(int _dimension)
    : dimension(_dimension)
    {
        values = new double[dimension];

        for (int i = 0; i < dimension; i++)
            values[i] = 0;
    }

    ~Vector()
    {
        delete [] values;
    }

    int getDimension() { return dimension; }

    double getValueAt(int index)
    {
        if (index < 0 || dimension <= index)
            throw runtime_error("Index van opsega");

        return values[index];
    }

    double operator [] (int index)
    {
        return getValueAt(index);
    }

    void setValueAt(int index, double value)
    {
        if (index < 0 || dimension <= index)
            throw runtime_error("Index van opsega");

        values[index] = value;
    }

    Vector operator + (Vector other)
    {
        /*
        int newDimension;

        if (dimension > other.dimension)
            newDimension = dimension;
        else
            newDimension = other.dimension;
        */

        int newDimension = (dimension > other.dimension) ? dimension
                           : other.dimension;

        double* newValues = new double[newDimension];

        for (int i = 0; i < newDimension; i++)
        {
            double left = (i < dimension) ? values[i] : 0;
            double right = (i < other.dimension) ? other.values[i] : 0;

            newValues[i] = left + right;
        }

        return Vector(newValues, newDimension);
    }

    Vector operator - (Vector other)
    {
        int newDimension = (dimension > other.dimension) ? dimension
                           : other.dimension;

        double* newValues = new double[newDimension];

        for (int i = 0; i < newDimension; i++)
        {
            double left = (i < dimension) ? values[i] : 0;
            double right = (i < other.dimension) ? other.values[i] : 0;

            newValues[i] = left - right;
        }

        return Vector(newValues, newDimension);
    }

    double operator * (Vector other)
    {
        double result = 0;

        int maxDimension = (dimension > other.dimension) ? dimension
                           : other.dimension;

        for (int i = 0; i < maxDimension; i++)
            result += values[i] * other.values[i];

        return result;
    }

    bool operator == (Vector other)
    {
        int maxDimension = (dimension > other.dimension) ? dimension
                           : other.dimension;

        for (int i = 0; i < maxDimension; i++)
        {
            double left = (i < dimension) ? values[i] : 0;
            double right = (i < other.dimension) ? other.values[i] : 0;

            if (left != right)
                return false;
        }

        return true;
    }
};

ostream& operator << (ostream& ostr, Vector v)
{
    ostr << "[";

    int dim = v.getDimension();

    for (int i = 0; i < dim; i++)
    {
        ostr << v.getValueAt(i);

        if (i < dim - 1)
            ostr << ", ";
    }

    ostr << "]";

    return ostr;
}

#endif // VECTOR_H_INCLUDED
