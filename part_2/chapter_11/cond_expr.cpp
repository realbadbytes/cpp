#include <iostream>

using namespace std;

int main()
{
    int a = 1;
    int b = 2;
    int max = 0;

    if (a <= b)
        max = b;
    else
        max = a;

    /* The equivalent conditional-expression */

    max = (a <= b) ? b : a;

    return 0;
}
