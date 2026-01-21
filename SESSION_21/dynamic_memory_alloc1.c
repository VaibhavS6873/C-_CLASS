#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void int_demo(void);
void double_demo(void);
void Date_demo(void);


int main(void)
{
    int_demo();
    double_demo();
    Date_demo();
}
void int_demo(void)
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

     free(p);
     p = NULL;
}

void double_demo(void)
{
    double* p;

    p = (double*)malloc(sizeof(int));

    if(NULL == p)
    {
        puts("Error in allocating memory");
        exit(-1);
    }

    *p = 5.5;
    printf("*p = %lf", *p);

    free(p);
    p = NULL;
}

void Date_demo(void)
{
    struct Date* pDate;
     
    pDate = (struct Date*)malloc(sizeof(Date));

    if(NULL == pDate)
    {
        puts("Error in allocating memory");
    }

    pDate->day = 15;
    pDate->month = 03;
    pDate->year = 2025;

    printf("%d / %d / %d \n", pDate->day, pDate->month, pDate->year);

    free(pDate);
    pDate = NULL;
}