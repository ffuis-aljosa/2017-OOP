#ifndef MONTHLYEMPLOYEE_H_INCLUDED
#define MONTHLYEMPLOYEE_H_INCLUDED

#include <stdexcept>

#include "Employee.h"

class MonthlyEmployee : public Employee
{
protected:
    int salary;
    int weeklyHours;
    int officeNumber;

public:
    MonthlyEmployee(string _firstName, string _lastName,
                    string _address, string _phoneNumber,
                    int _salary, int _weeklyHours,
                    int _officeNumber)
    : Employee(_firstName, _lastName, _address, _phoneNumber)
    {
        setSalary(_salary);
        setWeeklyHours(_weeklyHours);
        setOfficeNumber(_officeNumber);
    }

    void setSalary(int _salary)
    {
        if (_salary <= 0)
            throw runtime_error("Plata mora biti vec od 0");

        salary = _salary;
    }

    void setWeeklyHours(int _weeklyHours)
    {
        if (_weeklyHours < 20)
            throw runtime_error("Sedmicni broj radnih sati mora biti bar 20");

        if (_weeklyHours > 60)
            throw runtime_error("Sedmicni broj radnih sati mora biti najvise 60");

        if (_weeklyHours % 5 != 0)
            throw runtime_error("Sedmicni broj radnih sati mora biti djeljiv sa 5");

        weeklyHours = _weeklyHours;
    }

    void setOfficeNumber(int _officeNumber)
    {
        if (_officeNumber <= 0)
            throw runtime_error("Broj kancelarije ne moze biti 0 i manji");

        if (_officeNumber > 1000)
            throw runtime_error("Broj kancelarije mora biti najvise 1000");

        officeNumber = _officeNumber;
    }

    void describe()
    {
        Employee::describe();
        cout << salary << "KM za " << weeklyHours << " radnih sati sedmicno" << endl << endl;
    }

    int paycheck()
    {
        return salary;
    }
};

#endif // MONTHLYEMPLOYEE_H_INCLUDED
