/* g++ -std=c++11 -o string string.cpp */

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string compose(const string& name, const string& domain)
{
    return name  + '@' + domain;
}

int main()
{
    auto addr = compose("yee", "badbytes.io");

    /* printf doesnt know what a C++ string is, so must pass C string */
    printf("%s\n", addr.c_str());

    /* cout ostream knows how to handle C++ string type */
    cout << addr[2] << endl;
}
