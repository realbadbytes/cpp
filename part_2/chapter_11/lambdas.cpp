#include <iostream>


using namespace std;

void print_hello()
{
    cout << "Hi from lambda!" << endl;
}


int main()
{
    [] () { cout << "Hi from lambda!" << endl; } ();

    print_hello();

    return 0;
}
