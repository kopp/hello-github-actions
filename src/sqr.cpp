#include "sqr.hpp"
#include<iostream>

double sqr(double x)
{
    double y = x * x;
    std::cout << "  [sqr(" << x << ") = " << y << "]  ";
    return y;
}
