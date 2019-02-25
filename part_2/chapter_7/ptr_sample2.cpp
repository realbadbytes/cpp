#include <iostream>

using namespace std;

int main()
{
    /* pointer to int */
    int *a;

    /* pointer to a pointer to a char */
    /* b -> ? -> char */
    char **b;

    /* array of 10 int pointers, unintialized */
    int *dirty_c[10];

    /* array of 10 int pointers, intialized with brackets */
    int *clean_c[10]{};

    /* two int pointers, one on the heap, one on the stack */
    int *sample = new int(5);
    int sample2{10};

    /* place int pointers in improperly initialized pointer array */
    dirty_c[1] = sample;
    dirty_c[8] = &sample2;

    /* place int pointers in properly initialized pointer array */
    clean_c[1] = sample;
    clean_c[8] = &sample2;

    cout << "\ndirty_c: sample is at heap memory address " << dirty_c[1] << endl;
    cout << "dirty_c: sample dereferenced is " << *dirty_c[1] << endl;
    cout << "dirty_c: sample2 is at stack memory address " << dirty_c[8] << endl;
    cout << "dirty_c: sample2 dereferenced is " << *dirty_c[8] << endl;
    cout << "dirty_c: pointer array dirty_c contains: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << dirty_c[i] << endl;
    }

    cout << "\nclean_c: sample is at heap memory address " << clean_c[1] << endl;
    cout << "clean_c: sample dereferenced is " << *clean_c[1] << endl;
    cout << "clean_c: sample2 is at stack memory address " << clean_c[8] << endl;
    cout << "clean_c: sample2 dereferenced is " << *clean_c[8] << endl;
    cout << "clean_c: pointer array clean_c contains: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << clean_c[i] << endl;
    }

    /* pointer to an array of 10 ints */
    int (*d)[10];

    /* pointer to a function taking a char pointer */
    int (*fp)(char*);

    /* function returning an integer pointer taking a char pointer as argument */
    int *f(char*);

    return 0;
}
