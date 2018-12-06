#include <iostream>
using namespace std;


int main()
{
    double d_1 = 2.3;
    double d_2 {2.3};

    complex<double> z = 1;
    complex<double> z_2 {d1, d2};
    /* = is optional with {} initialization */
    complex<double> z_3 = {1, 2};

    vector<int> v {1, 2, 3, 4, 5, 6};

    /* ~DRAGONS~ */
    int i_1 = 7.2;  /* i_1 is 7 */
    int i_2 {7.2};  /* error */
    int i_3 = {7.2} /* error */

}
