#include <iostream>
#include <limits>

using namespace std;

int main()
{
    constexpr float min = numeric_limits<float>::min();
    cout << "smallest float on this system at compile time: " << min << endl;

    constexpr int szi = sizeof(int);
    cout << "int bytes on this system at compile time: " << szi << endl;

    return 0;
}
