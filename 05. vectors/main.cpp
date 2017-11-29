#include <iostream>

#include "Vector.h"

using namespace std;

int main()
{
    double array[] = { 4.6, 6.12, 9., 8.76 };
    Vector a(array, 4);

    cout << a[2] << endl;

    a.setValueAt(2, 7.8);

    cout << a << endl << endl;

    double bArray[] = { 6., 1.9, 5.2 };
    Vector b(bArray, 3);

    cout << a << " +" << endl
         << b << endl
         << a + b << endl << endl;

    cout << a << " -" << endl
         << b << endl
         << a - b << endl << endl;

    cout << a << " *" << endl
         << b << endl
         << a * b << endl << endl;

    Vector c = a = b;

    cout << a << endl << b << endl << c;

    return 0;
}
