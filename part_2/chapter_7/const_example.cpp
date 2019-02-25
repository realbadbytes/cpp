#include <iostream>

using namespace std;

int main()
{
    char stuff[] = "test";

    /* pointer to a const char */
    const char *ptr1 = stuff;

    /* const pointer to a char */
    char *const ptr2 = stuff;

    /* proof that ptr2's char is mutable */
    ptr2[3] = 'H';

    cout << ptr2 << endl;

    return 0;
}
