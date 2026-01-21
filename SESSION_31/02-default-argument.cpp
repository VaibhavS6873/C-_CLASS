#include<iostream>

int test(int a, int b = 5);

//int test_1(int a, int b = 5, int c); //CTE: Error,non-default cannot be placed after default

int test_2(int a = 50, int b = 300, int c = 400);

int main(void)
{
    int sum = test(10,20);
    std::cout<<"test(10,20):sum:"<<sum<<std::endl;
    sum = test(50); //sum == 55 because b = 5
    std::cout<<"test(50):sum:"<<sum<<std::endl;

    int result = test_2(); //a == 50, b == 300, c == 400
    std::cout<<"result:"<<result<<std::endl;

    return 0;
}

int test(int a, int b)
{
    return(a+b);
}

int test_2(int a, int b, int c)
{
    return a+b+c;
}