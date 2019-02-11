#include <thread>
#include <iostream>
#include <mutex>
#include <queue>
#include <cstdbool>
#include <chrono>
#include <condition_variable>

using namespace std;

// globals to allow threads to work together
queue<int> mqueue;
condition_variable mcond;
mutex mmutex;

void producer()
{
    for (int i = 100; i < 105; i++) {
        unique_lock<mutex> lck {mmutex};
        mqueue.push(i);
        cout << "producer - Pushed data to shared queue." << endl;
        mcond.notify_one();
        cout << "producer - Notifying consumer and sleeping." << endl;
        lck.unlock();
        this_thread::sleep_for( chrono::milliseconds(1000) );
    }
}

void consumer()
{
    while(true) {
        unique_lock<mutex> lck {mmutex};
        //cond_var.wait(lock, []() { return bool_var == true; })
        mcond.wait(lck, []() { return !mqueue.empty(); });
        auto m = mqueue.front();
        mqueue.pop();
        lck.unlock();
        cout << "consumer - Got " << m << " from shared queue." << endl;
        cout << "consumer - Waiting for notify." << endl;
    }
}

int main(int argc, char *argv[])
{
    thread prod(producer);
    thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}
