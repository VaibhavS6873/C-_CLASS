#include<iostream>
#include<functional>
#include<typeinfo>

std::function<int(int,int)>getFunction(void);

int main(void)
{
    int result = getFunction()(100,200);
    std::cout<<"Result:"<<result<<std::endl;
    return 0;
}

std::function<int(int,int)>getFunction()
{
    auto cpaAdd = [](int x, int y)->int{return x+y;};
    std::cout<<"typeinfo(cpaAdd):"<<typeid(cpaAdd).name()<<std::endl;
    return cpaAdd;
}