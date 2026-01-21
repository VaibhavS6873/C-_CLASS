#include<stdio.h>

void test_function(void);
void trigger(void);

int main(void)
{
    test_function();
    trigger();
    test_function();
    return 0;
}

void test_function(void)
{
    int x = 0;
    static int y = 0;

    x = x+5;
    y = y+5;

    printf("x = %d, y = %d\n",x,y);
    printf("adder(x) = %p , adder(y) = %p", &x,&y);
}

void trigger()
{
    float f_arr[5];
    int i;

    for(i = 0; i<5; ++i)
    {
        f_arr[i] = (i+1)/6.0;
    }

    test_function();
}