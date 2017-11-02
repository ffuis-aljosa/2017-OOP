#include <iostream>
//#include "email_c.h"
#include "email.h"

using namespace std;

int main()
{
    string* to = new string[2];
    to[0] = "prvi@email.com";
    to[1] = "drugi@email.com";
    // string to = (string*) malloc(sizeof(string) * 2);

    string* cc = new string[1];
    cc[0] = "treci@email.com";

    string content = "Postovani,\nSaljem Vam ispitna pitanja iz OOPa...";

    /*
    Email mail = constructEmail("valid@email.com", to, 2,
                                cc, 1,
                                NULL, 0,
                                "Ispitna pitanja iz OOPa",
                                content);

    printEmail(mail);
    */

    Email mail("valid@email.com", to, 2,
                cc, 1,
                NULL, 0,
                "Ispitna pitanja iz OOPa",
                content);

    mail.print();

    return 0;
}
