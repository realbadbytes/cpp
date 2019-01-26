/* g++ -std=c++11 -ggdb -o list_usage list_usage.cpp */

#include <iostream>
#include <list>


using namespace std;


int main()
{
    list<int> intlist = {1, 2, 3, 4, 5};

    /* Get an iterator and go to 3rd element */
    list<int>::iterator it = intlist.begin();
    ++it;

    /* Insert into list at iterator location */
    intlist.insert(it, 100);

    for (auto v : intlist) {
        cout << v << "\n";
    }
}
