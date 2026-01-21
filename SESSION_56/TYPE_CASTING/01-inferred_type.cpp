#include<iostream>
#include<typeinfo>

int main(void)
{
    int a = 10, b = 30;

    std::cout<<"type(a+b):"<<typeid(a+b).name()<<std::endl; //int
    std::cout<<"type(a+b):"<<typeid((float)(a+b)).name()<<std::endl; //float
    std::cout<<"type(a+b):"<<typeid(a+b).name()<<std::endl; //int
    return 0;
}