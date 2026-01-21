#include<iostream>

int test(int a,int b = 5);
int test(int m);

int main(void)
{
    //test(100); //CTE ambigous call error
    return 0;
}