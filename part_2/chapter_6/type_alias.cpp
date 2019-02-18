#include <iostream>

using namespace std;

int main()
{
    /* pointer to character */
    using ptr_to_char = char*;

    /* pointer to function taking a double and returning an int */
    using ptr_to_func = int(*)(double);

    typedef int int32_t;
    /* same as */
    using int32_t = int;

    typedef short int16_t;
    /* same as */
    using int16_t = short;

    using Char = char;
    using Uchar = signed Char; // ERROR
    //using Uchar = signed char; // OK

    Char *x;
    fgets(x, 1, stdin);
    cout << x << endl;

    return 0;
}
