#include <iostream>


using namespace std;


/* User-defined type describing a blog post. */
struct BlogPost {

    /* post name */
    const char* name;

    /* post author */
    const char* author;

    /* post tags i.e. "development" is "d" */
    char tags[13];

    /* word count */
    int length;
};


int main()
{
    BlogPost bp = { 
        "badbytes.io",
        "realbadbytes",
        {'d', 'c', 'n'},
        542
    };

    cout << "BlogPost bp size according to sizeof: " << sizeof(bp) << endl;

    return 0;
}
