// g++ -std=c++11 -o cpp_ptrs cpp_ptrs.cpp

#include <iostream>
#include <memory> // unique_ptr and shared_ptr

using namespace std;

int main(int argc, char **argv)
{
    shared_ptr<float> sample_a (new float(5.4551));

    cout << "shared_ptr sample_a ref count " << sample_a.use_count() << endl;

    shared_ptr<float> sample_b(sample_a);

    cout << "shared_ptr sample_a ref count " << sample_a.use_count() << endl;
    cout << "shared_ptr sample_b ref count " << sample_b.use_count() << endl;
    // The pointers now share the same raw pointer.
    // Thus each has ref count of 2 since they point to same place.

    // Delete managed object sample_b.
    sample_b.reset();
    // The raw pointer will not yet be deallocated, since there is still a ref to it by sample_a
    cout << "shared_ptr sample_a ref count " << sample_a.use_count() << endl;
    cout << "shared_ptr sample_b ref count " << sample_b.use_count() << endl;
    // Delete managed object sample_a.
    sample_a.reset();

    // All memory is freed since ref count is zero.
    cout << "shared_ptr sample_a ref count " << sample_a.use_count() << endl;
    cout << "shared_ptr sample_b ref count " << sample_b.use_count() << endl;

    return 0;
}
