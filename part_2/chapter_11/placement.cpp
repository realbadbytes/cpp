#include <iostream>
#include <new>

using namespace std;

int main()
{
    char buffer[1024];

    /* Using new to place data at a specific address */

    /* syntax: new (address) (type) initializer */

    int* placed_1 = new (buffer) int(1337);
    int* placed_2 = new (buffer) int(4141);

    cout << "Address of `buffer` on stack: " << &buffer << endl;
    cout << "Address of `placed_1`: " << placed_1 << endl;
    cout << "Address of `placed_2`: " << placed_2 << endl;


    /* Using new to overwrite some stack space 0x500 bytes away from the stack.
     * Don't do this! 
     */

    /* Get stack addr */
    void *p = NULL;
    int* write_location = (int*)&p - 0x500;

    cout << "Before overwrite " << write_location << " has " << *write_location << endl;
    int* dont_do_this = new (write_location) int(6161);
    cout << "After overwrite " << write_location << " has " << *write_location << endl;


    return 0;
}
