#include<stdio.h>
#include<stdlib.h>

const int gc_num  = 100;

int main(void)
{
    const int lc_num = 200;

    //gc_num = 1000; //CTE
    //lc_num = 2000; //CTE
    static const int x = 3000; 
    int* ptr = NULL;
    int* ptr1 = NULL;

    ptr = &lc_num; //C compiler issues warning
                   //that it is discarding const
    printf("Before *ptr = 1000: *ptr = %d\n",*ptr);
    *ptr = 2000;
    printf("After *ptr = 1000: *ptr = %d\n",*ptr);

    //thoda next level cha knowledge
    const int lc_num_1 = 500;
    ptr = &lc_num_1; //Compile time warning

    printf("Before *ptr = 5000: *ptr = %d\n",lc_num_1);
    *ptr = 5000;
    printf("After *ptr = 5000: *ptr = %d\n",lc_num_1); //ithe 500 ch print hota because it is said that consider 
                                                        //const variables as symbolic const i.e. #define type 
                                                        //tyamule compile time lach value takli jate ji ki 500
    ptr = &gc_num; //compile time warning

    printf("Before *ptr = 1000: *ptr = %d\n",gc_num);
    *ptr = 1000; //segmentation fault here as trying to update data in RODATA section
    printf("After *ptr = 1000: *ptr = %d\n",gc_num); 

    puts("Application terminated successfully");
    return 0;
}