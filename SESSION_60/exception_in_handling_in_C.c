#include<stdio.h>
#include<stdlib.h>
#include<setjmp.h>

void f1(int n);
void f2(int n);
void f3(int n);
void f4(int n);

jmp_buf jump_buffer;

int main(void)
{
    int arr[] = {10,20,-30,40,50,-60,70,-80};
    int i;
    int return_value;

    i = 0;

    return_value = setjmp(jump_buffer);
    if(return_value == 0)
    {
        puts("Jump location is set");
    }
    else if(return_value == 1)
    {
        puts("Sorry, for negative number");
        i = i+1;
    }

    while(i < sizeof(arr)/sizeof(arr[0]))
    {
        printf("------------i = %d-------------\n",i);
        f1(arr[i]);
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
        longjmp(jump_buffer, 1);
        //exit(0); //don't play god over here
    }
    else
    {
        printf("Square of %d is %d\n",n,n*n);
    }
}
