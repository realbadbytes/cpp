#include <iostream>

using namespace std;

struct T {
    int a;
    double b;
    char c;
};

int main()
{
    auto ac = alignof(char);
    auto ai = alignof(int);
    auto at = alignof(T);

    cout << "char alignment: " << ac << endl;
    cout << "int alignment: " << ai << endl;
    cout << "T alignment: " << at << endl;

    return 0;
}
