#include<iostream>
#include<functional>
#include<typeinfo>

int cpaAdd(int, int);
int (*getFunctionAddress())(int,int);

int main(void)
{
    int result = getFunctionAddress()(100,200);
    std::cout<<"Result = "<<result<<std::endl;
    return 0;
}

int cpaAdd(int x, int y)
{
    return x + y;
}

int (*getFunctionAddress())(int,int)
{
    return cpaAdd;
}