#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void int_demo(void);
void float_demo(void);
void Date_demo(void);

int main(void)
{
    int *p = NULL;
     p = (int*)malloc(sizeof(int));
     if(p == NULL)
     {
        puts("Error in allocating memory");
        exit(-1);
     }    

     *p = 100;
     printf("*p = %d\n", *p);
}