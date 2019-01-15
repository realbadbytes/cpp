// g++ -std=c++11 -o enum_classes enum_classes.cpp

#include <iostream>
using namespace std;


enum class TrafficLight { green, 
                          yellow, 
                          red };


TrafficLight& operator++(TrafficLight& t)
{
    switch(t) {
        case TrafficLight::green:
            return t=TrafficLight::yellow;

        case TrafficLight::yellow:
            return t=TrafficLight::red;

        case TrafficLight::red:
            return t=TrafficLight::green;

        }
}

/* define the << operator for cout and TrafficLight! */
std::ostream& operator<<(std::ostream& out, TrafficLight t)
{
    switch(t)
    {
        case TrafficLight::green:
            out << "green";
            break;
        case TrafficLight::yellow:
            out << "yellow";
            break;
        case TrafficLight::red:
            out << "red";
            break;
        default:
            out << "wat";
            break;
    }

    return out;
}


int main()
{
    int light_cycle = 0;
    TrafficLight light = TrafficLight::red;

    while(light_cycle < 3) {
        cout << "Traffic light is " << light << "\n";
        ++light;
        light_cycle++;
    }
   
    return 0;
}









