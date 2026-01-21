#include<iostream>

int myAdd(int,int);
int mySub(int,int);
int myMul(int,int);

class BinaryFunction
{
    private:
        int(*pfn)(int,int);

    public:
        BinaryFunction(int (*_pfn)(int,int)):pfn(_pfn)
        {
        }

        int operator()(int opnd1,int opnd2)
        {
            return pfn(opnd1,opnd2);
        }
};

int main(void)
{
    BinaryFunction bFn1(myAdd), bFn2(mySub), bFn3(myMul);

    int m = 10, n = 7;
    int result;

    result = bFn1(m, n);
    std::cout<<"Result of bFn1(m,n):"<<result<<std::endl;

    result = bFn2(m, n);
    std::cout<<"Result of bFn2(m,n):"<<result<<std::endl;

    result = bFn3(m, n);
    std::cout<<"result:"<<result<<std::endl;

    return 0;
}

int myAdd(int a, int b)
{
    return (a+b);
}

int mySub(int a, int b)
{
    return (a-b);
}

int myMul(int a, int b)
{
    return (a*b);
}