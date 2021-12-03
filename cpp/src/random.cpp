#include "../include/advancedQFcpp_bits/random.hpp"
#include <iostream>
#include <cmath>
#include <cstdlib>

double SampleBoxMuller::operator()()
{

    do
    {
        x = 2. * rand() / static_cast<double>(RAND_MAX) - 1;

        y = 2. * rand() / static_cast<double>(RAND_MAX) - 1;

        xysquare = x * x + y * y;
    } while (xysquare >= 1.);

    result = x * sqrt(-2 * log(xysquare) / xysquare);
    return result;
}