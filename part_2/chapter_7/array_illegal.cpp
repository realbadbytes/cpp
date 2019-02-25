#include <iostream>

using namespace std;

int main()
{
    /* legal, normal list initialization */
    int v5[] = {1, 2, 3, 4};

    int v6[4] = v5;

    v6 = v5;

    return 0;
}
