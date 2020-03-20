#include<iostream>
#include "version.h"
#ifdef USE_MYSQUARE
#include "sqr.hpp"
#else
float sqr(float x) { return x * x; }
#endif

int main()
{
    std::cout << "hello world" << std::endl;
    std::cout << "In version " << VERSION << " of the project " << NAME << std::endl;
    double x = 3;
    std::cout << "Square of " << x << " is " << sqr(x) << std::endl;
}
