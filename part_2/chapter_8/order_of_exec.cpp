#include <iostream>

using namespace std;


int f(int x)
{
    cout << "in f()\n";
    return x * 2;
}


int g(int x)
{
    cout << "in g()\n";
    return x * 3;
}


int main()
{

    /* undefined behavior */
    int x = f(2) + g(6);
    cout << "x: " << x << endl;

    int v[4];
    int i = 1;
    /* undefined behavior
     * could be either v[1] = 1 or v[2] = 1; */
    v[i] = i++;
    cout << "v[i]: " << v[i] << endl;

    return 0;
}
