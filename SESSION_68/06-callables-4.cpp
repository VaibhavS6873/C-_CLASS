#include<iostream>
#include<typeinfo>
#include<functional>

class Callable
{
    private:
        std::function<int(int,int)>funcObject;

    public:
        Callable(std::function<int(int,int)> _funcObject) : funcObject(_funcObject){}

        int operator()(int x, int y)
        {
            return funcObject(x,y);
        }
};

int main(void)
{
    Callable C([](int x, int y)->int {return x+y;});
    int result = C(100,200);
    std::cout<<"Result:"<<result<<std::endl;

    return 0;
}