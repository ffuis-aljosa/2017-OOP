#ifndef EMAIL_H_INCLUDED
#define EMAIL_H_INCLUDED

#include <regex>

using namespace std;

class Email
{
private:
    string from;
    string* to;
    int toSize;
    string* cc;
    int ccSize;
    string* bcc;
    int bccSize;
    string title;
    string content;

    bool isValidEmail(string s)
    {
        regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

        return regex_match(s, emailRegex);
    }

    void validateEmail(string s, int exitCode)
    {
        if (!isValidEmail(s))
            exit(exitCode);
    }

    void validateEmails(string* emails, int size, int exitCode)
    {
        for (int i = 0; i < size; i++)
            validateEmail(emails[i], exitCode);
    }

    void printEmails(string* emails, int size)
    {
        for (int i = 0; i < size; i++)
        {
            cout << emails[i];

            if (i < size - 1)
                cout << ", ";
        }
    }

public:
    Email(string _from,
          string* _to, int _toSize,
          string* _cc, int _ccSize,
          string* _bcc, int _bccSize,
          string _title, string _content)
    {
        validateEmail(_from, 1);
        from = _from;

        if (_to == NULL || _toSize == 0)
            exit(2);

        validateEmails(_to, _toSize, 3);

        to = _to;
        toSize = _toSize;

        if (_cc == NULL || _ccSize == 0)
        {
            cc = NULL;
            ccSize = 0;
        }
        else
        {
            validateEmails(_cc, _ccSize, 4);

            cc = _cc;
            ccSize = _ccSize;
        }

        if (_bcc == NULL || _bccSize == 0)
        {
            bcc = NULL;
            bccSize = 0;
        }
        else
        {
            validateEmails(_bcc, _bccSize, 5);

            bcc = _bcc;
            bccSize = _bccSize;
        }

        if (_title.size() > 128)
            exit(6);

        title = _title;
        content = _content;
    }

    void print()
    {
        cout << "from: " << from << endl
         << "to: ";

        printEmails(to, toSize);

        cout << endl;

        cout << "cc: ";

        if (ccSize == 0)
            cout << "<EMPTY>";
        else
            printEmails(cc, ccSize);

        cout << endl;

        cout << "bcc: ";

        if (bccSize == 0)
            cout << "<EMPTY>";
        else
            printEmails(bcc, bccSize);

        cout << endl
             << "title: " << title << endl
             << endl
             << content << endl;
    }
};

#endif // EMAIL_H_INCLUDED
