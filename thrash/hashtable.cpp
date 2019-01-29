// g++ -std=c++11 -ggdb -o hashtable hashtable.cpp

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

int hash_func(TableEntry *t)
{

    int hash_value = 0;

    string s = t->s;

    for (int c : s) {

        /* Using int gets the ascii code */
        hash_value += c;

    }

    /* Divide by number of elements in the hash table, save remainder as hash code
     * aka modulus 
     */
    cout << "hash of \"" << s << "\" is " << hash_value % 5 << endl;

    return hash_value % 5;
}


TableEntry* alloc_tableentry(string s, int data)
{

    TableEntry *ptr = (struct TableEntry *) malloc(sizeof(struct TableEntry));

    if (ptr == nullptr) {

        cout << "malloc() has failed. Exiting\n" << endl;

    }

    ptr->next = nullptr;
    ptr->s = s;
    ptr->data = data;

    return ptr;

}


void print_hashtable(TableEntry **hashtable, int slot_bitmap[])
{

    TableEntry *tmp = alloc_tableentry(" ", 0);

    /* Number of possible hashes is 5. */
    for (int i = 0; i < 5; i++) {

        cout << "Slot " << i << endl;

        /* If there is nothing in the hash table at this index */
        if (slot_bitmap[i] == 0) {

            continue;

        }

        tmp = hashtable[i];

        while (1) {

            cout << tmp->data << endl;
            tmp = tmp->next;

            /* End of the linked list. */
            if (tmp == nullptr) {

                break;

            }
        }
    }

    free(tmp);
}


int main(int argc, char *argv[])
{

    /* Actual entries */
    TableEntry *a = alloc_tableentry("algorithmicefficiency", 11111);
    TableEntry *b = alloc_tableentry("badcode", 22222);
    TableEntry *c = alloc_tableentry("g00dc00de", 33333);
    TableEntry *d = alloc_tableentry("hexdumps", 44444);
    TableEntry *e = alloc_tableentry("d3adc0de", 55555);

    /* Placeholder while doing chaining */
    TableEntry *tmp = alloc_tableentry(" ", 0);

    /* Original entry array */
    TableEntry *basictable[5] = {a, b, c, d, e};

    /* Hash table to insert into */
    TableEntry *hashtable[5] = {0};

    /* Tracking of which slots have valid entries */
    int slot_bitmap[5] = {0};

    int hash_value = 0;

    for (int i = 0; i < 5; i++) {

        hash_value = hash_func(basictable[i]);

        /* The slot is open */
        if (slot_bitmap[hash_value] == 0) {

            cout << "Found open slot at " << hash_value << endl;
            hashtable[hash_value] = basictable[i];
            cout << "Inserted \"" << hashtable[hash_value]->s << "\" at " << hash_value << endl;
            slot_bitmap[hash_value] = 1;

        }

        /* Collision */
        else {

            cout << "Collision at slot " << hash_value << endl;
            tmp = hashtable[hash_value];

            /* Iterate through linked list at hash */

            while (tmp->next != nullptr) {

                cout << "Traversing chained TableEntries" << endl;
                tmp = tmp->next;

            }

        /* Link new TableEntry to tail */
        cout << "Linking up TableEntry to tail at slot " << hash_value << endl;

        /* Follow next pointer */
        tmp->next = basictable[i];

        }

    }

    /* Check if it worked */

    print_hashtable(hashtable, slot_bitmap);

    free(a);
    free(b);
    free(c);
    free(d);
    free(e);
    free(tmp);

}
