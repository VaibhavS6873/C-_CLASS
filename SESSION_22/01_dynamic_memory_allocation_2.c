#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void int_arr_demo(void);
void float_arr_demo(void);
void date_arr_demo(void);

void int_arr_demo(void)
{
    int* a = NULL;
    int a_size = 5;
    int i;
    int val;

    a = (int*)malloc(a_size*sizeof(int));

    if(NULL == a)
    {
        puts("error");
        exit(-1);
    }

    for(i = 0; i < a_size; i++)
    {
        *(a+i) = (i+1)*100;
    }

    for(i = 0; i<5; i++)
    {
        val = a[i];// ptr variable name is used as if its a name of array
        printf("a[%d]: %d\n", i, val);
    }

    free(a);
    a = NULL;
}

void float_arr(void)
{
    float* p = NULL;
    int p_size = 5;
    int i;
    float val;

    p = (float*)malloc(p_size * sizeof(float));


    if(NULL == p)
    {
        puts("error");
        exit(-1);
    }

    for(i = 0; i<p_size; i++)
    {
        *(p+i) = (i+0.05)*100;
    }

    for(i = 0; i < 5; i++)
    {
        val = p[i];
        printf("p[%d]:%lf",i, val);
    }

    free(p);
    p = NULL;
}

void date_arr_demo(void)
{
    struct Date* pDate = NULL;
    int i;
    int date_size = 5;

    pDate = (struct Date*)malloc(date_size*sizeof(struct Date));

    if(NULL == pDate)
    {
        puts("error");
        exit(-1);
    }

    for(i = 0; i<date_size; i++)
    {
        pDate[i].day = i+2;
        pDate[i].month = 7-i;
        pDate[i].year = 2025;
    }

    for(i = 0; i<5; i++)
    {
        printf("Date object at index %d = %d / %d / %d \n ",
                pDate[i].day, pDate[i].month, pDate[i].year);
    }

    free(pDate);
    pDate = NULL;
}