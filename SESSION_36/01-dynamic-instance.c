#include<stdio.h>
#include<stdlib.h>


struct Date
{
    int day, month, year;
};

void getDateInstance(struct Date** ppDate);
void initDateInstance(struct Date* pDate, int init_day, int init_month, int init_year);
void releaseDateInstance(struct Date** ppDate);

void getDateInstance(struct Date** ppDate)
{
    struct Date* pDate = NULL;

    pDate = (struct Date*)malloc(sizeof(struct Date));
    if(NULL == pDate)
    {
        fprintf(stderr,"getDateInstance():malloc():fatal:out of memory\n");
        exit(EXIT_FAILURE);
    }

    *ppDate = pDate;
}

void releaseDateInstance(struct Date** ppDate)
{
    if(ppDate)
    {
        struct Date* pDate = *ppDate;
        if(pDate)
        {
            free(pDate);
            pDate = NULL;
            *ppDate = NULL;
        }
    }
}

void initDateInstance(struct Date* pDate, int init_day, int init_month, int init_year)
{
    pDate->day = init_day;
    pDate->month = init_month;
    pDate->year = init_year;
}