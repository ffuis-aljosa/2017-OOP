#include <iostream>

#include "Vector.h"

using namespace std;

void test()
{
    double array[] = { 4.6, 6.12, 9., 8.76 };
    Vector a(array, 4);

    cout << a;
}

int main()
{
    cout << 1 << endl;

    test();

    cout << 2 << endl;

    return 0;
}
