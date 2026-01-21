#include<cstdio>
#include<iostream>
#include<exception>

void f1(int n);
void f2(int n);
void f3(int n);
void f4(int n);

int main(void)
{
    int arr[] = {10,20,-30,40,50,-60,70,-80};
    int i;

    std::cout<<"--------EXCEPTION HANDLING C++ Version-------"<<std::endl;
    i = 0;

    while(i < sizeof(arr) / sizeof(arr[0]))
    {
        printf("-----------i = %d--------------\n",i);
        try
        {
            f1(arr[i]);
        }
        catch(std::runtime_error& e)
        {
            std::cerr << e.what() << std::endl;
        }

        i = i+1;
    }
}

void f1(int n)
{
    puts("block of statments in f1() before call to f2()");
    f2(n);
    puts("block of statments after returning from f2()");
}

void f2(int n)
{
    puts("block of statments in f2() before call to f3()");
    f3(n);
    puts("block of statments after returning from f3()");
}

void f3(int n)
{
    puts("block of statments in f3() before call to f4()");
    f4(n);
    puts("block of statments after returning from f4()");
}


void f4(int n)
{
    if(n < 0)
    {
        throw std::runtime_error("Sorry, negative number");
    }
    else
    {
        printf("Square of %d is %d\n",n,n*n);
    }
}