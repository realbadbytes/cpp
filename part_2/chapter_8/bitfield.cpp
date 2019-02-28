#include <iostream>

using namespace std;

struct BitFieldSample {

    /* 1 bit field indicating wind shear */
    bool wind_shear : 1;

    /* 3 bit field to indicate weather type */
    unsigned int weather_type : 3;

    /* 57 bit flag field for various flags */
    unsigned long int operational_flags : 57;

    /* unnamed 1 bit field to 8-byte align the struct in memory */
    unsigned int : 3;

};

int main()
{
    BitFieldSample bfs;

    cout << "BitFieldSample is " << sizeof(bfs) << " bytes.\n" << endl;

    return 0;
}
