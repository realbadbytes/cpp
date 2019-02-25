#include <iostream>
#include <vector>

using namespace std;

void f(int n)
{
    vector<int> arr(n);
}

int main()
{
    /* array on the stack */
    int v[10];

    /* arrays on the heap */
    int *vz = new int[40];
    int *vs = (int *) malloc(20);

    /* create a vector using a function */
    /* vector uses arrays in its implementation */
    f(10);

    /* make sure to deallocate the heap array with the proper functions:
     * malloc and free
     * new and delete
     * new[] and delete[] 
     */
    delete[](vz);
    free(vs);

    return 0;
}
