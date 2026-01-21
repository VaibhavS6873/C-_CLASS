#include<iostream>
#include<typeinfo>


class B
{
    public:
        virtual ~B(){}
};

class D1 : public B
{
    public:
        void g1()
        {
            puts("In D1::g1()");
        }
};

class D2 : public B
{
    public:
        void g2()
        {
            puts("In D2::g2()");
        }
};

class D3:public B
{
    public:
        void g3()
        {
            puts("In D3::g3()");
        }
};

int main(void)
{
    int n;
    B* pB = 0;
    std::cout<<"Enter n (between 1 to 3):";
    std::cin>>n;

    if(n == 1)
    {
        pB = new D1;
    }
    else if(n == 2)
    {
        pB = new D2;
    }
    else if(n == 3)
    {
        pB = new D3;
    }
    else
    {
        puts("bad choice");
        exit(-1);
    }

    //pB contains address of object of class D1 or D2 or D3
    
}