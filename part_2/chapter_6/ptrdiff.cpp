#include <iostream>
#include <cstddef>

using namespace std;

int main()
{
    // used for array size
    const size_t N = 10;

    // allocate a 10 int array 
    int* a = new int[N];

    // get pointer to end of array
    int* end = a + N;

    // loop backwards through the array
    for (ptrdiff_t i = N; i > 0; --i) {

        // for each pointer, set the value to i
        cout << (* (end - i) = i) << ' ';

    }

    delete[] a;

    return 0;
}

