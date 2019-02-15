// g++ -std=c++11 -o rando rando.cpp
#include <random>
#include <functional>
#include <chrono>
#include <iostream>

using namespace std;

int main()
{
    default_random_engine engine {};
    // Seed the engine so it makes new numbers each time.
    engine.seed(std::chrono::system_clock::now().time_since_epoch().count());
    // Set the value map.
    uniform_int_distribution<> distro {1, 100};
    // Bind the engine and map together.
    // bind() makes a function object that will invoke its first argument
    // given its second argument as its argument. So, distro(engine);
    auto die = bind(distro, engine);
    for (int i = 0; i < 10; i++) {
        cout << die() << endl;
    }

    return 0;
}
