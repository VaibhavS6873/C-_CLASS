#include<stdio.h>
#include<stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

void arr_of_ptr_to_int_demo(void);
void arr_of_ptr_to_date_demo(void);


int main(void)
{
    arr_of_ptr_to_int_demo();
    arr_of_ptr_to_date_demo();

    return 0;
}


void arr_of_ptr_to_int_demo(void)
{
    int **pptr = NULL;
    int i;
    int arr_size = 5;
    int val;

    pptr = (int**)malloc(arr_size * sizeof(int*));

    if(NULL == pptr)
    {
        puts("error");
        exit(-1);
    }

    for(i = 0; i < arr_size; i++)
    {
        pptr[i] = (int*)malloc(sizeof(int));

        if(NULL == pptr[i])
        {
            puts("error");
            exit(-1);
        }
    }

    // write on dynamically allocated integers block 
    for(i = 0; i < arr_size; i++)
    {
        *pptr[i] = (i+1) * 100;
    }

     // read from dynamically allocated integers block 
     for(i = 0; i < arr_size; i++)
     {
        val = *pptr[i];
        printf("*pptr[%d]:%d", i, val);
     }

         // free integers block 
    for(i = 0; i < arr_size; i++)
    {
        free(pptr[i]);
        pptr[i] = NULL;
    }

    free(pptr);
    pptr = NULL;
}

void arr_of_ptr_to_date_demo(void)
{
    struct Date** ppDate = NULL;
    int i;
    int date_size = 5;
    int curr_day, curr_month, curr_year;

    ppDate = (struct Date**)malloc(date_size * sizeof(struct Date*));

    if(NULL == ppDate)
    {
        puts("error");
        exit(-1);
    }

    for(i = 0; i < date_size; i++)
    {
        ppDate[i] = (struct Date*)malloc(sizeof(struct Date));

        if(NULL == ppDate[i])
        {
            puts("error");
            exit(-1);
        }
    }

    for(i = 0; i<date_size; i++)
    {
        ppDate[i]->day = 19-i;
        ppDate[i]->month = 7-i;
        ppDate[i]->year = 2025;
    }

    for(i = 0; i<date_size; i++)
    {
        curr_day = ppDate[i]->day;
        curr_month = ppDate[i]->month;
        curr_year = ppDate[i]->year;

        printf("Date at index %d: %d/%d/%d\n", curr_day, curr_month, curr_year);
    }

    for(i = 0; i<date_size; i++)
    {
        free(ppDate[i]);
        ppDate[i] = NULL;
    }

    free(ppDate);
    ppDate = NULL;
} 