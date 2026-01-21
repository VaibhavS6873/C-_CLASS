#include<iostream>
#include "max.hpp"


int main(void)
{
    int x = 10, y = 20;
    double p = 1.1, q = 2.2;
    int i_max;
    double d_max;

    i_max = max<int>(x,y); //here <int> is template parameter
    d_max = max<double>(p,q);
    
    return 0;
}