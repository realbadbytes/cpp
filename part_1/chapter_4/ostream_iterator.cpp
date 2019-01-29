#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> ii {cin};
    ostream_iterator<int> oo {cout};

    /* Write a vector to cout via iterator */
    vector<int> v {1, 3, 5, 7, 9};
    copy(v.begin(), v.end(), oo);

    /* Read 5 elements into the vector via iterator */
    copy_n(ii, 5, back_inserter(v));

    /* Write it back out to cout */
    copy(v.begin(), v.end(), oo);
}
