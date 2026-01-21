#include<iostream>

int& func();

int main(void)
{
    int& ref = func();
    std::cout<<"main():&ref:"<<std::hex<<&ref<<std::endl;
    std::cout<<"main():ref:"<<std::dec<<ref<<std::endl;

    delete &ref;
    std::cout<<" main():deleted successfully. existing app"<<std::endl;
    return 0;
}

int& func()
{
    std::cout<<"----Entered func()-----"<<std::endl;
    int* p = new int(100);

    std::cout<<"func():address in p (returned by new):"<<std::hex<<p<<std::endl;
    std::cout<<"----Leaving func()-----"<<std::endl;
    return *p;
}