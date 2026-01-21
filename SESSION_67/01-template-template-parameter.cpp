#include<iostream>
#include<typeinfo>

/*
template <typename T, std::size_t size> class stack
{
    private:
        T* pa;
        std::size_t N;
        std::topIndex;
    public:
        Stack() : pa(new T[size]), N(size),topIndex(0)
        {}
};

int num;     //num is an int
int* p;     //p is a pointer to int
const int* p;  //p is a pointer to const int
int* const p = &num;  //p is a const pointer to int
const int* const p = &num; //p is a const pointer to const int
*/

int f(int x, int y);
int g(int u, int v);

template <typename T1, typename T2> class CT1
{
    public:
        CT1(){
            std::cout<<"----In Class template CT1()----"<<std::endl;
            std::cout<<"Currently CT1 is instantiated by"<<std::endl
                <<typeid(T1).name()<<"and"<<typeid(T2).name()<<std::endl;
        }
};

template <typename T1, typename T2> class CT2
{
    private:
        T1 x;
        T2 y;

    public:
        CT2(){
            std::cout<<"----In Class template CT2()----"<<std::endl
                <<"type(x):"<<typeid(x).name()<<"and type(y):"<<typeid(y).name()<<std::endl;
        }
};

template <template <typename X, typename Y>class CONTAINER, typename C1, typename C2> void testFunction()
{
    std::cout<<"----In testFunction()----"<<std::endl;
    CONTAINER<C1, C2>objectOfContainer;
    std::cout<<"Typenames have been printed"<<std::endl;
    std::cout<<"----Leaving testFunction()----"<<std::endl;
}

int main(void)
{
    testFunction<CT1, int, double>();
    testFunction<CT2, char, float>();
    return 0;
}

/*
    //template defination
    template<int X>
    void testFunction(){}

    //template instantation
    testFunction<10>();

    #---------------------------

    //template defination
    template <typename T>
    void testFunction(){}

    //template instantiate
    testFunction<int>();

    #-----------------------------

    template<template <ashi ashi ahe>class VAIBHAV>
    void testFunction(){}

    testFunction<ashi ashi template paramter list asnara kuthlahi class template>();

    10               int
    int              typename T
    std::vector      template<>class CONT
*/