#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

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

    Vector(double* _values, int _dimension)
    : dimension(_dimension)
    {
        cout << endl << "Konstruktor" << endl;

        values = new double[dimension];

        for (int i = 0; i < dimension; i++)
            values[i] = _values[i];
    }

    ~Vector()
    {
        cout << endl << "Destruktor" << endl;

        delete [] values;
    }

    int getDimension() { return dimension; }
    double getValueAt(int index) { return values[index]; }
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
