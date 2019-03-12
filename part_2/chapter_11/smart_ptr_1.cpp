#include <memory>
#include <iostream>

using namespace std;

int main()
{   
    unique_ptr<int> ptr1 {new int(99)};

    cout << "ptr1 = " << *ptr1 << " at " << ptr1.get() << endl;

    /* Transfer ownership to ptr2 */
    unique_ptr<int> ptr2 { move(ptr1) };

    /* Should be the same address as the old ptr1 */
    cout << "ptr2 = " << *ptr2 << " at " << ptr2.get() << endl;

    /* Causes segfault because ptr1 no longer exists. */
    cout << "ptr1 = " << *ptr1 << endl;

    return 0;
}
