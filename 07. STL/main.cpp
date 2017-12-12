#include <iostream>

#include <vector>
#include <list>

using namespace std;

template<class T>
void printList(list<T> l)
{
    typename list<T>::iterator temp;

    for (temp = l.begin(); temp != l.end(); temp++)
        cout << *temp << endl;


    cout << endl << endl;
}

int main()
{
    vector<string> names;

    names.push_back("Marko");
    names.push_back("Marija");
    names.push_back("Vanja");

    int size = names.size();

    for (int i = 0; i < size; i++)
        cout << names[i] << endl;

    cout << endl << endl;

    list<double> l;

    l.push_back(14.5123);
    l.push_front(7.41);
    l.push_back(12.1254125);
    l.push_back(218.214);
    l.push_front(711.41);
    l.push_back(112.12451);

    //cout << l.front() << " " << l.back() << endl;

    printList(l);

    list<double>::iterator it = l.begin();
    it++;
    it++;

    l.insert(it, 3, 0);

    printList(l);

    l.unique();

    printList(l);

    l.sort();

    printList(l);

    return 0;
}
