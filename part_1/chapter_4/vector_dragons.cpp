/* vector does not perform range checking (why not?) */

#include <vector>
#include <iostream>

using namespace std;


int main()
{
    vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    nums[nums.size()] = 44;
    cout << "i is " << nums[nums.size()] << endl;
    return 0;
}
