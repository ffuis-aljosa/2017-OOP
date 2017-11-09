#include <iostream>

#include "complexNumber.h"

#include <stdexcept>

using namespace std;

// polymorfism

void print(int a)
{
    cout << "int " << a << endl;
}

void print(float a)
{
    cout << "float " << a << endl;
}

void print(ComplexNumber a)
{
    cout << "complex "
         << a.getReal() << " + " << a.getImaginary() << "i" << endl;
}

int main()
{
    print(7.5f);

    ComplexNumber a;

    print(a);

    ComplexNumber z(13.2, 5.78);

    print(z);

    z.setReal(15);
    z.setImaginary(75);

    print(z);

    print(z.add(15));

    a.setReal(19);
    a.setImaginary(-9);

    print(z.add(a));
    print(z + a);

    print(z - a);
    print(z * a);

    print(z / a);

    ComplexNumber b;

    try
    {
        print(a + z * (z / b) - a - a);
    }
    catch(runtime_error error)
    {
        cout << "Desila se neka greska pri racunanju! " << error.what() << endl;
    }

    cout << (z == a) << endl;
    cout << (z != z) << endl;
    cout << (z != a) << endl;
    cout << z.modulus() << endl;

    return 0;
}
