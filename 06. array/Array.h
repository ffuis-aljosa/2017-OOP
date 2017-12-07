#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdexcept>

using namespace std;

template<class T>
class Array
{
private:
    T* values;
    int size;

    void validateIndex(int index, int max)
    {
        if (index < 0 || index > max)
            throw runtime_error("Index out of bounds");
    }

public:
    Array()
    : values(NULL), size(0)
    {}

    Array(const Array& array)
    : size(array.size)
    {
        values = new T[size];

        for (int i = 0; i < size; i++)
            values[i] = array.values[i];
    }

    Array operator = (Array array)
    {
        size = array.size;

        delete [] values;

        values = new T[size];

        for (int i = 0; i < size; i++)
            values[i] = array.values[i];

        return *this;
    }

    ~Array()
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
    }

    void add(T value, int index)
    {
        validateIndex(index, size);

        T* newValues = new T[size + 1];

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

        T* newValues = new T[size - 1];

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

    void change(T value, int index)
    {
        validateIndex(index, size - 1);

        values[index] = value;
    }

    T operator[] (int index)
    {
        validateIndex(index, size - 1);

        return values[index];
    }
};

template<class U>
ostream& operator << (ostream& ostr, Array<U>& a)
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

#endif // ARRAY_H_INCLUDED
