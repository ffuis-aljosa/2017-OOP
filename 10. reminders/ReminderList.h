#ifndef REMINDERLIST_H_INCLUDED
#define REMINDERLIST_H_INCLUDED

#include <vector>
#include <stdexcept>
#include "Reminder.h"

using namespace std;

class ReminderList
{
private:
    vector<Reminder> reminders;
    DateTime createdAt;
    string title;

public:
    ReminderList(DateTime _createdAt, string _title)
    : createdAt(_createdAt), title(_title)
    {}

    void addReminder(Reminder reminder)
    {
        reminders.push_back(reminder);
    }

    void removeReminderAt(int index)
    {
        if (index < 0 || reminders.size() <= index)
            throw runtime_error("Pogresan index");

        vector<Reminder>::iterator it = reminders.begin();

        for (int i = 0; i < index; i++)
            it++;

        reminders.erase(it);
    }

    void completeAt(int index)
    {
        if (index < 0 || reminders.size() <= index)
            throw runtime_error("Pogresan index");

        reminders[index].setFinished(true);
    }

    void printAll()
    {
        int size = reminders.size();

        for (int i = 0; i < size; i++)
            cout << reminders[i] << endl;
    }

    void printUnfinished()
    {
        int size = reminders.size();

        for (int i = 0; i < size; i++)
            if (!reminders[i].getFinished())
                cout << reminders[i] << endl;
    }

    int countWithAlarm()
    {
        int count = 0;
        int size = reminders.size();

        for (int i = 0; i < size; i++)
            if (reminders[i].getHasAlarm())
                count++;

        return count;
    }
};

#endif // REMINDERLIST_H_INCLUDED
