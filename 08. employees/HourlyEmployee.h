#ifndef HOURLYEMPLOYEE_H_INCLUDED
#define HOURLYEMPLOYEE_H_INCLUDED

#include "stdexcept"

#include "Employee.h"

using namespace std;

class HourlyEmployee : public Employee
{
protected:
    int hourlyRate;
    int hoursWorked;

public:
    HourlyEmployee(string _firstName, string _lastName,
                   string _address, string _phoneNumber,
                   int _hourlyRate, int _hoursWorked)
    : Employee(_firstName, _lastName, _address, _phoneNumber)
    {
        setHourlyRate(_hourlyRate);
        setHoursWorked(_hoursWorked);
    }

    void setHourlyRate(int _hourlyRate)
    {
        if (_hourlyRate <= 0)
            throw runtime_error("Satnica mora biti pozitivna");

        hourlyRate = _hourlyRate;
    }

    void setHoursWorked(int _hoursWorked)
    {
        if (_hoursWorked < 0)
            throw runtime_error("Broj sati rada ne moze biti negativan");

        hoursWorked = _hoursWorked;
    }

    void describe()
    {
        Employee::describe();
        cout << hoursWorked << " sati, za po " << hourlyRate << "KM po satu" << endl << endl;
    }

    int paycheck()
    {
        return hourlyRate * hoursWorked;
    }
};

#endif // HOURLYEMPLOYEE_H_INCLUDED
