#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include <stdexcept>

using namespace std;

class Employee
{
protected:
    string firstName;
    string lastName;
    string address;
    string phoneNumber;

public:
    Employee(string _firstName, string _lastName,
             string _address, string _phoneNumber)
    {
        setFirstName(_firstName);
        setLastName(_lastName);
        setAddress(_address);
        setPhoneNumber(_phoneNumber);
    }

    void setFirstName(string _firstName)
    {
        if (_firstName == "")
            throw runtime_error("Ime ne moze biti prazno");

        firstName = _firstName;
    }

    void setLastName(string _lastName)
    {
        if (_lastName == "")
            throw runtime_error("Prezime ne moze biti prazno");

        lastName = _lastName;
    }

    void setAddress(string _address)
    {
        if (_address == "")
            throw runtime_error("Adres ne moze biti prazna");

        address = _address;
    }

    void setPhoneNumber(string _phoneNumber)
    {
        if (_phoneNumber == "")
            throw runtime_error("Broj telefona ne moze biti prazan");

        phoneNumber = _phoneNumber;
    }

    virtual void describe()
    {
        cout << firstName << " " << lastName << " zivi na adresi: " << address << endl
             << "Za isplatu: " << paycheck() << "KM" << endl;
    }

    virtual int paycheck() = 0;
};

#endif // EMPLOYEE_H_INCLUDED
