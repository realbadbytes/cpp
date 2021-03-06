/* Vector implementation with newly added error handling 
 * C++ provides error handling mainly through the Type system */

#include "Vector.h"
#include <iostream>
#include <stdexcept>

using namespace std;


Vector::Vector(int s)
{
    elem = new double[s];
    sz = s;
}

/* For example, lets ensure no out of bounds access
 * or at least make the user aware that it is happening */
double& Vector::operator[](int i)
{
    if (i < 0 || size() <= i) {
        /* throw an exception and hope the library code user
         * has implemented an exception handler
         * note: out_of_range type is defined in <stdexcept> */
        throw out_of_range{"Vector::operator[]"};
    }
    return elem[i];
}


int Vector::size() const
{
    return sz;
}

int main()
{
    Vector v(1000);
    double a = v[1]; // ok
    double b = v[2000]; //oob
    return 0;
}
