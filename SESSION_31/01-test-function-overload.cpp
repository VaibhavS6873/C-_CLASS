#include<iostream>

void test(long p, long q);
void test(int a, int b);
void test(int m);
void test(float f);

int main(void)
{
    test(100,200);
    test(30);
    //test(5.5); CTE as due to ambiguity as 5.5 can be treated as int or float and in reality 5.5 is double whose fun is not present
    return 0;
}

void test(int a, int b)
{
    std::cout<<"--------Entered test() with void test(int a, int b) called--------"<<std::endl;
    std::cout<<"--------Leaving test() with void test(int a, int b)called---------"<<std::endl;
}

void test(long p, long q)
{
    std::cout<<"--------Entered test() with void test(long p, long q) called--------"<<std::endl;
    std::cout<<"--------Leaving test() with void test(long p, long q) called---------"<<std::endl;
}

void test(int m)
{
    std::cout<<"---------Entered test() with void test(int m) called--------"<<std::endl;
    std::cout<<"---------Leaving test() with void test(int m) called---------"<<std::endl;
}

void test(float f)
{
    std::cout<<"---------Entered test() with void test(float f) called--------"<<std::endl;
    std::cout<<"---------Leaving test() with void test(float f) called---------"<<std::endl;
}
