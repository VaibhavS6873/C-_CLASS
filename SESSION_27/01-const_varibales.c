#include<stdio.h>
#include<stdlib.h>

int g_num = 10; //normal data defination statement
const int gc_num = 100;

int main(void)
{
    g_num = 200;
   // gc_num = 200;  //CTE //gc_num is not modifiable lvalue

    return 0;
}