#include <thread>
#include <iostream>

using namespace std;

void func(int x)
{
    for (int i = 0; i < 50; i++) {
        // There is a bad mistake here. 
        // Access to the stdout ostream is not controlled.
        // Output will be erratic.
        cout << "Thread " << x << endl;
        // Take a thread nap.
        this_thread::sleep_for(chrono::milliseconds(50));
    }
}

int main(int argc, char *argv[])
{
    // Create two threads.
    // Thread constructor takes the callback function, followed by args to that function.
    thread t1( func, 1 );
    thread t2( func, 2 );
    thread t3( func, 3 );
    thread t4( func, 4 );

    // Wait for threads to finish execution before leaving the main() thread.
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}
