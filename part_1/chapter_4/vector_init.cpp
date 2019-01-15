#include <vector>
#include <iostream>

using namespace std;


int main()
{
    vector<int> v1 = {1, 2, 3, 4};
    vector<string> v2;
    vector<char> v3(23);
    vector<double> v4(8, 9.9);

    cout << "v1 size: " << v1.size() << endl;
    cout << "v1[2]: " << v1[2] << endl;

    cout << "v2 size: " << v2.size() << endl;

    cout << "v3 size: " << v3.size() << endl;
    cout << "v3 vector contents: " << endl;
    for (int i = 0; i != v3.size(); ++i) {
        cout << v3[i];
    }

    cout << "v4 size: " << v4.size() << endl;
    cout << "v4 vector contents: " << endl;
    for (int i = 0; i != v4.size(); ++i) {
        cout << v4[i] << " ";
    }
    cout << endl;

    return 0;
}
