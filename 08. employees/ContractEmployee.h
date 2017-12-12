#ifndef CONTRACTEMPLOYEE_H_INCLUDED
#define CONTRACTEMPLOYEE_H_INCLUDED

#include <stdexcept>

#include "Employee.h"

using namespace std;

class ContractEmployee : public Employee
{
protected:
    int contractLength;
    int contractWorth;

public:
    ContractEmployee(string _firstName, string _lastName,
                     string _address, string _phoneNumber,
                     int _contractLength, int _contractWorth)
    : Employee(_firstName, _lastName, _address, _phoneNumber)
    {
        setContractLength(_contractLength);
        setContractWorth(_contractWorth);
    }

    void setContractLength(int _contractLength)
    {
        if (_contractLength <= 0)
            throw runtime_error("Trajanje ugovora mora biti vece od 0");

        contractLength = _contractLength;
    }

    void setContractWorth(int _contractWorth)
    {
        if (_contractWorth <= 0)
            throw runtime_error("Vrijednost ugovora mora biti veca od 0");

        contractWorth = _contractWorth;
    }

    void describe()
    {
        Employee::describe();
        cout << "Po ugovoru od " << contractLength << " dana za "
             << contractWorth << "KM" << endl << endl;
    }

    int paycheck()
    {
        return contractWorth;
    }
};

#endif // CONTRACTEMPLOYEE_H_INCLUDED
