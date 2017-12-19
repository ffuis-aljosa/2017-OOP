#include <iostream>

#include "Circle.h"
#include "Triangle.h"
#include "Rectangle.h"

using namespace std;

int main()
{
    Circle c("K", Point(1, 2), 4);

    cout << c.area() << " " << c.circumference() << endl;

    Triangle t("T", Point(), Point(2, 3), Point(8, -3));

    cout << t.area() << " " << t.circumference() << endl;

    Rectangle r("P", Point(5, 3), 6, 9);

    cout << r.area() << " " << r.circumference() << endl;

    return 0;
}
