#include <iostream>

using namespace std;

char* test_literal()
{
    return "TEST_STRING_LITERAL";
}

int main()
{
    cout << test_literal() << endl;
    return 0;
}
