#include<iostream>

class A
{
    public:
        void operator() ()
        {
            std::cout<<"Hello from A::operator()"<<std::endl;
            std::cout<<"Leave from A::operator()"<<std::endl;
        }
};

class B
{
    public:
        float operator() (int nr, int dr)
        {
            return ((float)nr)/dr;
        }
};

int main(void)
{
    A objA;
    objA();

    B objB;
    int m = 10, n = 7;
    float result = objB(m,n);
    std::cout<<"Result:"<<result<<std::endl;
    return 0;
}