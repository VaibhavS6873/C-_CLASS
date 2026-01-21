#include<stdio.h>
#include<stdlib.h>

struct A
{
    double d;
    int* i_ptr;
};

int main(void)
{
    struct A* A_ptr = NULL;

    A_ptr = (struct A*)malloc(sizeof(struct A));

    if(NULL == A_ptr)
    {
        puts("Error");
        exit(-1);
    }

    A_ptr->d = 34.67;

    A_ptr->i_ptr = (int*)malloc(sizeof(int));

    if(NULL == A_ptr->i_ptr)
    {
        puts("Error");
        exit(-1);
    }

    *A_ptr->i_ptr = 100;

    printf("double val = %lf and int val = %d", A_ptr->d, *A_ptr->i_ptr);
    return 0;
}