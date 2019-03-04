#include <memory>
#include <iostream>

using namespace std;

int main()
{
    unique_ptr<int> ptr1 {new int(99)};

    cout << "ptr1 = " << *ptr1 << endl;

    /* Now we make a new ptr and move the values from old ptr into it
     * this causes the reference count of ptr1 to become 0, and it
     * is then garbage collected.
     */

    unique_ptr<int> ptr2 { move(ptr1) };

    cout << "ptr2 = " << *ptr2 << endl;

    /* Causes segfault because ptr1 no longer exists. */
    cout << "ptr1 = " << *ptr1 << endl;

    return 0;
}
