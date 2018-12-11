#include "Vector.h"
#include <cmath>
#include <stdio.h>

using namespace std;


double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i = 0; i != v.size(); ++i)
    {
        sum += sqrt(v[i]);
    }
    return sum;
}


int main()
{
    Vector vec = Vector(10);
    printf("%f\n", sqrt_sum(vec));
    return 0;
}

