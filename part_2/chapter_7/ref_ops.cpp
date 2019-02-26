#include <iostream>

using namespace std;

int main()
{
    /* int on the stack */
    int x = 0;

    /* x_ref now refers to x on the stack */
    int& x_ref {x};

    cout << x_ref << endl;

    /* operator does not operate on the reference itself */
    ++x_ref;

    cout << x_ref << endl;

    /* get a pointer to the object referred to by x_ref 
     * this gives us the "address of x" on the stack */
    int *x_ptr = &x_ref;

    cout << *x_ptr << endl;

    return 0;
}
