#include <string>
#include <iostream>

using namespace std;

/*
 * Find index number using the value at the index itself.
 * aka hash, or "map" the data to the index
 * This hash function will get the ascii code of each char and add them together
 * to compute the hash.
 *
 * Inserting elements into a hash table based on this method will eventually 
 * yield collisions, i.e items with the same hash value. One solution for this
 * is linear probing/open addressing, where if an item cant be inserted at its
 * proper hashed location, it moves up the hash table into the first available spot.
 */
int hash_func(string s)
{
    int hash_value = 0;

    for (int c : s) {
        /* Using int gets the ascii code */
        hash_value += c;
    }
    /* Divide by number of elements in the hash table, save remainder as hash code
     * aka modulus 
     */
    cout << "hash of \"" << s << "\" is " << hash_value % 10 << endl;
    return hash_value % 10;
}



int main(int argc, char *argv[])
{

    string a = "bad";
    string b = "bytes";
    string c = "yee";
    string d = "noooo";
    string e = "whatyouwannado";
    string f = "google";
    string g = "microsoft";
    string h = "amazon";
    string i = "asusmonitors are nice";
    string j = "dogfish head craft brewed ales";

    string name_array[] = {a, b, c, d, e, f, g, h, i, j};

    cout << "Using hash table" << endl;
    for (int i = 0; i < 10; i++) {
        hash_func(name_array[i]);
    }

}

