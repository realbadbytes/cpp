#include <iostream>

using namespace std;

int main()
{
    char c = 255;   // 0xFF
    int i = c;      // undefined behavior
    cout << c << endl;
    cout << i << endl;
    return 0;
}
