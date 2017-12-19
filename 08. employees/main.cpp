#include <iostream>

#include "Employee.h"
#include "MonthlyEmployee.h"
#include "HourlyEmployee.h"
#include "ContractEmployee.h"

#include <vector>

using namespace std;

int main()
{
    MonthlyEmployee m("Filip", "Jovanovic", "Vuka Karadzica 38", "065123154",
                      1800, 40, 138);
    HourlyEmployee h("Jovana", "Petrovic", "Vilijama Sekspira 3", "066836102",
                     35, 13);
    ContractEmployee c("Danka", "Boskovic", "Jovan Ducica bb", "062737124",
                       10, 800);

    Employee* emp = new HourlyEmployee("Goran", "milosevic", "Kasindo bb",
                                       "066543891", 40, 23);

    cout << emp->paycheck() << endl;

    cout << m.paycheck() << endl;

    vector<Employee*> employees;

    employees.push_back(&m);
    employees.push_back(&h);
    employees.push_back(&c);

    int size = employees.size();

    for (int i = 0; i < size; i++)
        cout << employees[i]->paycheck() << endl;

    delete emp;

    return 0;
}
