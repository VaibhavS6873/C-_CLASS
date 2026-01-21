#include<iostream>
#include<typeinfo>
#include<functional>

int cpaAdd(int,int);

class Callable
{
    private:
        int (*pfn)(int,int);

        public:
            Callable(int(*_pfn)(int,int)) : pfn(_pfn){}

            int operator()(int x, int y)
            {
                return pfn(x, y);
            }
};

int main(void)
{
    Callable C(cpaAdd);

    int result = C(100,200);
    std::cout<<"Result:"<<result<<std::endl;

    return 0;
}

int cpaAdd(int x, int y)
{
    return x + y;
}