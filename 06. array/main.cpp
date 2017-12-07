#include <iostream>

#include "IntArray.h"
#include "Array.h"

using namespace std;

template<class T>
void _swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

void testSwap()
{
    int x = 4, y = 18;

    _swap(x, y);

    float f1 = 9.1, f2 = 2.5;

    _swap(f1, f2);

    cout << x << ", " << y << endl;
    cout << f1 << ", " << f2 << endl;
}

int main()
{
    Array<int> a;

    a.addToBack(3);
    a.addToBack(17);
    a.addToBack(32);

    cout << a << endl;

    a.addToBack(-5);
    a.addToBack(305);

    cout << a << endl;

    a.add(0, 3);

    cout << a << endl;

    a.addToFront(11);

    cout << a << endl;

    a.remove(4);

    cout << a << endl;

    a.remove(1);

    cout << a << endl;

    a.removeFromFront();
    a.removeFromBack();

    cout << a << endl;

    a.change(404, 1);

    cout << a << endl;

    return 0;
}
