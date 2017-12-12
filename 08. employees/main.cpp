#include <iostream>

#include "Employee.h"
#include "MonthlyEmployee.h"
#include "HourlyEmployee.h"
#include "ContractEmployee.h"

using namespace std;

int main()
{
    MonthlyEmployee m("Filip", "Jovanovic", "Vuka Karadzica 38", "065123154",
                      1800, 40, 138);

    m.describe();

    HourlyEmployee h("Jovana", "Petrovic", "Vilijama Sekspira 3", "066836102",
                     35, 13);

    h.describe();

    ContractEmployee c("Danka", "Boskovic", "Jovan Ducica bb", "062737124",
                       10, 800);

    c.describe();

    return 0;
}
