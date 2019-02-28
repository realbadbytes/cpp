#include <iostream>

using namespace std;

int main()
{
    int i = 1;

    switch (i) {

        case 0:

            int x;
            int y = 3;

        case 1:

            cout << "x is " << x << endl;
            x++;
            /* use of uninitialize variable if case 0 is never hit! */
    }

    return 0;
}
