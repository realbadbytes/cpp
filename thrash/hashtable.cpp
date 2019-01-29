#include <string>
#include <iostream>

using namespace std;


/* Hash table entry struct to support closed addressing */
struct TableEntry {
    TableEntry* next;
    string s;
    int data;
};


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
 * A second solution is closed addressing where each spot in the hash table can 
 * hold a linked list of items that matched that hash code.
 */
int hash_func(TableEntry t)
{
    int hash_value = 0;
    string s = t.s;

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


void print_hashtable(TableEntry *hashtable)
{
    /* Number of possible hashes is 10 */
    for (int i = 0; i < 5; i++) {
        cout << hashtable[i]->data << endl;
        while (hashtable[i]->next != nullptr) {
            cout << hashtable[i]->data << endl;
        }
    }
}


int main(int argc, char *argv[])
{

    TableEntry *a = (struct TableEntry *) malloc(sizeof(struct TableEntry));
    a->next = nullptr;
    a->s = "bad";
    a->data = 111111;


    TableEntry *b = (struct TableEntry *) malloc(sizeof(struct TableEntry));
    b->next = nullptr;
    b->s = "algorithmicefficiency";
    b->data = 77777;


    TableEntry *c = (struct TableEntry *) malloc(sizeof(struct TableEntry));
    c->next = nullptr;
    c->s = "badcode";
    c->data = 22222;


    TableEntry *d = (struct TableEntry *) malloc(sizeof(struct TableEntry));
    d->next = nullptr;
    d->s = "goodcode";
    d->data = 101011;


    TableEntry *e = (struct TableEntry *) malloc(sizeof(struct TableEntry));
    e->next = nullptr;
    e->s = "d3adc0de";
    e->data = 99999;


    TableEntry *tmp = (struct TableEntry *) malloc(sizeof(struct TableEntry));
    tmp->next = nullptr;
    tmp->s = "";
    tmp->data = 0;


    TableEntry *basictable[5] = {a, b, c, d, e};

    TableEntry *hashtable[5] = {0};

    int hash_value = 0;

    for (int i = 0; i < 5; i++) {

        hash_value = hash_func(basictable[i]);

        tmp = hashtable[hash_value];

        /* The slot is open */
        if (tmp->data == 0) {
            cout << "Found open slot at " << hash_value << endl;

            hashtable[hash_value] = basictable[i];

            cout << "Inserted \"" << hashtable[hash_value]->s << "\" at " << hash_value << endl;

        }

        /* Collision */
        else {
            cout << "Collision at slot " << hash_value << endl;

            /* Iterate through linked list at hash */
            while (tmp->next != nullptr) {
                cout << "Traversing chained TableEntries" << endl;

                tmp = tmp->next;

            }

        /* Link new TableEntry to tail */
        cout << "Linking up TableEntry to tail at slot " << hash_value << endl;
        tmp->next = basictable[i];

        }

    }

    /* Check if it worked */
    print_hashtable(hashtable);

}






