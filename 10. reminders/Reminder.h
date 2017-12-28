#ifndef REMINDER_H_INCLUDED
#define REMINDER_H_INCLUDED

#include "DateTime.h"

using namespace std;

class Reminder
{
private:
    DateTime createdAt;
    string message;
    bool hasAlarm;
    DateTime alarmTime;
    bool finished;

public:
    Reminder(DateTime _createdAt, string _message)
    : createdAt(_createdAt), message(_message), hasAlarm(false),
      finished(false)
    {}

    Reminder(DateTime _createdAt, string _message, DateTime _alarmTime)
    : createdAt(_createdAt), message(_message), hasAlarm(true),
      alarmTime(_alarmTime), finished(false)
    {}

    string getMessage() { return message; }
    bool getFinished() { return finished; }
    DateTime getCreatedAt() { return createdAt; }
    DateTime getAlarmTime() { return alarmTime; }
    bool getHasAlarm() { return hasAlarm; }

    void setMessage(string _message) { message = _message; }
    void setFinished(bool _finished) { finished = _finished; }

    void snooze()
    {
        alarmTime + 600;
    }
};

ostream& operator << (ostream& ostr, Reminder r)
{
    ostr << (r.getFinished() ? 'X' : '-') << " " << r.getMessage()
         << " [" << r.getCreatedAt() << "]";

    if (r.getHasAlarm())
        ostr << " alarm @ " << r.getAlarmTime();

    return ostr;
}

#endif // REMINDER_H_INCLUDED
