#ifndef INTARRAY_H_INCLUDED
#define INTARRAY_H_INCLUDED

#include <stdexcept>

using namespace std;

class IntArray
{
private:
    int* values;
    int size;

    void validateIndex(int index, int max)
    {
        if (index < 0 || index > max)
            throw runtime_error("Index out of bounds");
    }

public:
    IntArray()
    : values(NULL), size(0)
    {}

    IntArray(const IntArray& array)
    : size(array.size)
    {
        values = new int[size];

        for (int i = 0; i < size; i++)
            values[i] = array.values[i];
    }

    IntArray operator = (IntArray array)
    {
        size = array.size;

        delete [] values;

        values = new int[size];

        for (int i = 0; i < size; i++)
            values[i] = array.values[i];

        return *this;
    }

    ~IntArray()
    {
        delete [] values;
    }

    int getSize() { return size; }

    void addToFront(int value)
    {
        add(value, 0);
    }

    void addToBack(int value)
    {
        add(value, size);

        /*
        int* newValues = new int[size + 1];

        for (int i = 0; i < size; i++)
            newValues[i] = values[i];

        newValues[size] = value;

        delete [] values;

        values = newValues;

        size++;
        */
    }

    void add(int value, int index)
    {
        validateIndex(index, size);

        int* newValues = new int[size + 1];

        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (i == index)
            {
                newValues[i] = value;
                continue;
            }

            newValues[i] = values[j];
            j++;
        }

        delete [] values;

        values = newValues;

        size++;
    }

    void remove(int index)
    {
        validateIndex(index, size - 1);

        int* newValues = new int[size - 1];

        for (int i = 0, j = 0; i < size; i++)
        {
            if (i == index)
                continue;

            newValues[j] = values[i];
            j++;
        }

        delete [] values;

        values = newValues;

        size--;
    }

    void removeFromFront()
    {
        remove(0);
    }

    void removeFromBack()
    {
        remove(size - 1);
    }

    void change(int value, int index)
    {
        validateIndex(index, size - 1);

        values[index] = value;
    }

    int operator[] (int index)
    {
        validateIndex(index, size - 1);

        return values[index];
    }
};

ostream& operator << (ostream& ostr, IntArray& a)
{
    ostr << "[";

    int size = a.getSize();

    for (int i = 0; i < size; i++)
    {
        ostr << a[i];

        if (i < size - 1)
            ostr << ", ";
    }

    ostr << "]";
}

#endif // INTARRAY_H_INCLUDED
