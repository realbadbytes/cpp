#include <iostream>

using namespace std;


void func1(int x)
{
    cout << x << endl;
}


void func2(bool x)
{
    cout << x << endl;
}


int main()
{
    int x = 99;

    int *x_ptr = &x;

    func1(x_ptr);

    func2(x_ptr);

    return 0;
}
