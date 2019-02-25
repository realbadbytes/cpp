#include <iostream>

using namespace std;

int main()
{
    char c = 'a';

    /* the pointer p holds the address of c */
    char *p = &c;

    /* follow p's pointer to get the value at c, aka dereference */
    char c2 = *p;

    cout << c << endl;
    cout << c2 << endl;

    return 0;
}
