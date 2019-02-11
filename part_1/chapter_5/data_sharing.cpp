#include <thread>
#include <mutex>
#include <memory>
#include <iostream>

using namespace std;

class Record {
    public:
        int data;
        int get_data();
        void set_data(int d);
    private:
        mutex class_mutex;
};

void Record::set_data(int d)
{
    // lock guard is a mutex wrapper providing RAII style mutex ownership.
    // Said another way, the mutex is gotten when lk is created, and the mutex 
    // will be released when this function ends.
    lock_guard<mutex> lk(class_mutex);
    this->data = d;
}

int Record::get_data()
{
    return data;
}

int main(int argc, char *argv[])
{
    // Ensure that threads are synchronized.
    // Data access should occur in a controlled manner.
    Record rm;
    rm.set_data(30);

    thread t1(rm.set_data, 10);
    cout << rm.get_data() << endl;

    thread t2(rm.set_data, 20);
    cout << rm.get_data() << endl;

    t1.join();
    t2.join();

    return 0;
}
