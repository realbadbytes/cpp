#include <vector>
#include <string>
#include <iostream>


using namespace std;


void print_names(const vector<string>& names)
{
    for (int i = 0; i < names.size(); ++i) {
        cout << names[i] << endl;
    }
}


int main()
{
    vector<string> names = {"bad", "bytes", "yee"};
    print_names(names);
    return 0;
}
