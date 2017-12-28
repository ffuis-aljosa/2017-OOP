#include <iostream>
#include <stdexcept>

#include "DateTime.h"
#include "Reminder.h"
#include "ReminderList.h"

using namespace std;

int main()
{
    try
    {
        DateTime dt(2017, 2, 13, 13, 0, 0);

        cout << dt << endl;

        dt + 12345678;

        cout << dt << endl;

        Reminder r(dt, "Kupi mlijeko");

        cout << r << endl;

        Reminder r1(dt, "Sastanak sa sefom", DateTime(2017, 5, 15, 12, 30, 0));
        r1.setFinished(true);

        cout << r1 << endl;

        cout << endl << endl;

        ReminderList list(dt, "Vazna lista zadataka");
        list.addReminder(r1);
        list.addReminder(r);
        list.addReminder(Reminder(dt, "Uciti za ispite",
                                  DateTime(2017, 12, 31, 0, 0, 0)));

        list.printAll();

        cout << endl << endl;

        list.printUnfinished();

        cout << endl << endl;

        cout << "Sa alarmom " << list.countWithAlarm() << endl;
    }
    catch(runtime_error error)
    {
        cerr << error.what() << endl;
    }

    return 0;
}
