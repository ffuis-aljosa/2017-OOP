#ifndef EMAIL_C_H_INCLUDED
#define EMAIL_C_H_INCLUDED

#include <stdlib.h>
#include <regex>

using namespace std;

struct _email
{
    string from;
    string* to;
    int toSize;
    string* cc;
    int ccSize;
    string* bcc;
    int bccSize;
    string title;
    string content;
};

typedef struct _email Email;

bool _isValidEmail(string s)
{
    regex emailRegex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    return regex_match(s, emailRegex);
}

void _validateEmail(string s, int exitCode)
{
    if (!_isValidEmail(s))
        exit(exitCode);
}

void _validateEmails(string* emails, int size, int exitCode)
{
    for (int i = 0; i < size; i++)
        _validateEmail(emails[i], exitCode);
}

Email constructEmail(string from,
                     string* to, int toSize,
                     string* cc, int ccSize,
                     string* bcc, int bccSize,
                     string title, string content)
{
    Email newEmail;

    _validateEmail(from, 1);
    newEmail.from = from;

    if (to == NULL || toSize == 0)
        exit(2);

    _validateEmails(to, toSize, 3);

    newEmail.to = to;
    newEmail.toSize = toSize;

    if (cc == NULL || ccSize == 0)
    {
        newEmail.cc = NULL;
        newEmail.ccSize = 0;
    }
    else
    {
        _validateEmails(cc, ccSize, 4);

        newEmail.cc = cc;
        newEmail.ccSize = ccSize;
    }

    if (bcc == NULL || bccSize == 0)
    {
        newEmail.bcc = NULL;
        newEmail.bccSize = 0;
    }
    else
    {
        _validateEmails(bcc, bccSize, 5);

        newEmail.bcc = bcc;
        newEmail.bccSize = bccSize;
    }

    if (title.size() > 128)
        exit(6);

    newEmail.title = title;
    newEmail.content = content;

    return newEmail;
}

void _printEmails(string* emails, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << emails[i];

        if (i < size - 1)
            cout << ", ";
    }
}

void printEmail(Email mail)
{
    cout << "from: " << mail.from << endl
         << "to: ";

    _printEmails(mail.to, mail.toSize);

    cout << endl;

    cout << "cc: ";

    if (mail.ccSize == 0)
        cout << "<EMPTY>";
    else
        _printEmails(mail.cc, mail.ccSize);

    cout << endl;

    cout << "bcc: ";

    if (mail.bccSize == 0)
        cout << "<EMPTY>";
    else
        _printEmails(mail.bcc, mail.bccSize);

    cout << endl
         << "title: " << mail.title << endl
         << endl
         << mail.content << endl;
}

#endif // EMAIL_C_H_INCLUDED
