#include <iostream>
#include <string>


using namespace std;


struct Entry {
    string name;
    int number;
};


/* user-defined type output */
ostream& operator<< (ostream& os, const Entry& e)
{
    return os << "{\"" << e.name << "\"," << e.number << "}" << endl;
}


/* user-defined type input */
istream& operator>> (istream& is, Entry& e)
{
    char c;
    char c2;
    if (is >> c && c == '{' && is >> c2 && c2 == '"') {
        string name;
        while (is.get(c) && c != '"') {
            name += c;
        }
        if (is >> c && c == ',') {
            int number = 0;
            if (is >> number >> c && c == '}') {
                e = {name,number};
                return is;
            }
        }
    }

    is.setstate(ios_base::failbit);
    return is;
}


int main()
{
    /*
    for (Entry ee; cin >> ee;) {
        cout << ee << endl;
    }
    */

    Entry ee;
    cin >> ee;
    cout << ee;
    return 0;
}




