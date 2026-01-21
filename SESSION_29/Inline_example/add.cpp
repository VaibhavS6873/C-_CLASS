#include<iostream>
#include "add.hpp"

int main(void)
{
    int n1 = 100;
    int n2 = 200;

    int max_num = max(1300,240);
    std::cout<<"max_num:"<<max_num<<std::endl;
    max_num = max(n1,n2);
    std::cout<<"max_num:"<<max_num<<std::endl;
    return 0;
}