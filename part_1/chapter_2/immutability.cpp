#include <iostream>
using namespace std;


double square(double x)
{
    return x*x;
}

int main()
{
    /* const: i promise not to change this value */
    const int dmv = 17; // named constant in RO memory
    int var = 17; // not a constant, goes on the stack

    /* constexpr: to be evaluated at compile time. place data in read-only memory.  */
    constexpr double max1 = 1.4*square(dmv); // ok if square(17) is a constant expression
    constexpr double max2 = 1.4*square(var); // var is not a constant expression, error.
    const double max3 = 1.4*square(var); // evaluated at runtime
}
