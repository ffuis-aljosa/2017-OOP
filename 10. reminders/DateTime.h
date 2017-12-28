#ifndef DATETIME_H_INCLUDED
#define DATETIME_H_INCLUDED

#include <stdexcept>

using namespace std;

class DateTime
{
private:
    int year;
    int month;
    int day;
    int hours;
    int minutes;
    int seconds;

    int maxDay(int _year, int _month)
    {
        if ((_month <= 7 && _month % 2 == 1) || (_month > 7 && _month % 2 == 0))
            return 31;

        if (_month >= 4)
            return 30;

        if ((_year % 4 == 0) && (_year % 100 != 0))
            return 29;

        if ((_year % 4 != 0) || (_year % 100 == 0))
            return 28;
    }

    void validateYear(int _year)
    {
        if (_year <= 0)
            throw runtime_error("Godina mora biti pozitivna");
    }

    void validateMonth(int _month)
    {
        if (_month < 1 || 12 < _month)
            throw runtime_error("Mjesec mora biti izmedju 1 i 12");
    }

    void validateDay(int _year, int _month, int _day)
    {
        if (_day < 1)
            throw runtime_error("Dan ne moze biti manji od 1");

        if (_day > maxDay(_year, _month))
            throw runtime_error("Dan je prevelik");
    }

    void validateHours(int _hours)
    {
        if (_hours < 0 || 23 < _hours)
            throw runtime_error("Sati moraju biti izmedju 0 i 23");
    }

    void validateMinutes(int _minutes)
    {
        if (_minutes < 0 || 59 < _minutes)
            throw runtime_error("Minute mora biti izmedju 0 i 59");
    }

    void validateSeconds(int _seconds)
    {
        if (_seconds < 0 || 59 < _seconds)
            throw runtime_error("Sekunde mora biti izmedju 0 i 59");
    }

public:
    DateTime()
    : year(1), month(1), day(1), hours(0), minutes(0), seconds(0)
    {}

    DateTime(int _year, int _month, int _day,
             int _hours, int _minutes, int _seconds)
    {
        validateYear(_year);
        validateMonth(_month);
        validateDay(_year, _month, _day);
        validateHours(_hours);
        validateMinutes(_minutes);
        validateSeconds(_seconds);

        year = _year;
        month = _month;
        day = _day;
        hours = _hours;
        minutes = _minutes;
        seconds = _seconds;
    }

    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getHours() { return hours; }
    int getMinutes() { return minutes; }
    int getSeconds() { return seconds; }

    void operator + (int sec)
    {
        seconds += sec;

        if (seconds < 60)
            return;

        minutes += seconds / 60;
        seconds = seconds % 60;

        if (minutes < 60)
            return;

        hours += minutes / 60;
        minutes = minutes % 60;

        if (hours < 24)
            return;

        day += hours / 24;
        hours = hours % 24;

        int max = maxDay(year, month);

        while (day > max)
        {
            month++;

            if (month > 12)
            {
                year++;
                month -= 12;
            }

            day -= max;
            max = maxDay(year, month);
        }
    }
};

ostream& operator << (ostream& ostr, DateTime dt)
{
    ostr << dt.getYear() << "-";

    int month = dt.getMonth();

    if (month < 10)
        ostr << '0';

    ostr << month << "-";

    int day = dt.getDay();

    if (day < 10)
        ostr << '0';

    ostr << day << " ";

    int hours = dt.getHours();

    if (hours < 10)
        ostr << '0';

    ostr << hours << ":";

    int minutes = dt.getMinutes();

    if (minutes < 10)
        ostr << '0';

    ostr << minutes << ":";

    int seconds = dt.getSeconds();

    if (seconds < 10)
        ostr << '0';

    ostr << seconds;

    return ostr;
}

#endif // DATETIME_H_INCLUDED
