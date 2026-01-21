#include<iostream>
#include<typeinfo>

template<typename T1, typename T2 = int>
class CT1
{
    private:
        T1 obj1;
        T2 obj2;

    public:
        CT1()
        {
            std::cout<<"typename(obj1):"<<typeid(obj1).name()<<std::endl;
            std::cout<<"typename(obj2):"<<typeid(obj2).name()<<std::endl;
        }
};

int main(void)
{
    CT1<double>X1; //CT1<double,int>
    CT1<double,double>X2;

    return 0;
}