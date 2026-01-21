#include<iostream>
#include<typeinfo> //for typeid() operator

class Base
{
    public:
        //Default constructor
        Base(){}

        virtual void f()
        {

        }
};

class Derived : public Base
{
    public:
        //Defualt constructor
        Derived() : Base()
        {

        }
};

int main(void)
{
    Base objBase;
    Derived objDerived;

    Base* pBaseOne = 0;
    Base* pBaseTwo = 0;

    std::cout<<"typeid(objBase):"<<typeid(objBase).name()<<std::endl;
    std::cout<<"typeid(objDerived):"<<typeid(objDerived).name()<<std::endl;

    pBaseOne = new Base;
    pBaseTwo = new Derived;

    std::cout<<"typeid(pBaseOne):"<<typeid(pBaseOne).name()<<std::endl; //Base*
    std::cout<<"typeid(pBaseTwo):"<<typeid(pBaseTwo).name()<<std::endl; //Base*

    std::cout<<"typeid(*pBaseOne):"<<typeid(*pBaseOne).name()<<std::endl; //Base
    std::cout<<"typeid(*pBaseTwo):"<<typeid(*pBaseTwo).name()<<std::endl; //Derived

    return 0;
}
