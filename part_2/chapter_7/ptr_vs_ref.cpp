#include <iostream>

using namespace std;

struct TestContainer {
    int x;
};

int main()
{
    /* Pointer to int*/
    TestContainer *ptr = new TestContainer {7};

    /* Create a reference to that int */
    TestContainer& ref {*ptr};

    /* Accessing data via pointer uses different syntax than the struct object itself */
    cout << "using the pointer: "<< ptr->x << endl;

    /* Accessing data via reference uses the same syntax as the struct object itself. */
    cout << "using the reference: "<< ref.x << endl;

    TestContainer tc {5};
    /* Accessing struct data directly, same as using a reference */
    cout << "direct access: " << tc.x << endl;

    return 0;
}
