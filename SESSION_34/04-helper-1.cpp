#include<iostream>

int get_int_1(void);
int* get_int_2(void);
int* get_int_3(void);
int* get_int_4(void);
void get_int_5(int** ppInt);

void test(void);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    //for get_int_1()
    int result_1;
    result_1 = get_int_1();

    //for get_int_2()
    int* ptr2 = NULL;
    ptr2 = get_int_2();
    //ptr2 will have an address of freed variable num allocated in the stack
    //frame of most recent call
    //Dereferencing this pointer will have an undefined result. That result may
    //be a successful access to value 100

    //for get_int_3()
    int* ptr3 = NULL;
    ptr3 = get_int_3();
     // dont free ptr3 (will be known from help or documentation)


     //for get_int_4()
     int* ptr4 = NULL;
     ptr4 = get_int_4();
     //use *ptr4
     free(ptr4);
     ptr4 = NULL;

     //for get_int_5()
     int* ptr5 = NULL;
     get_int_5(&ptr5);
     //ptr5 contains valid address
     free(ptr5);
     ptr5 = NULL;
}

int get_int_1(void)
{
    return 100;
}

int* get_int_2(void)
{
    int num = 100;
    return (&num);
    /* 
        You are returning an address of memory block 
        which will no longer exist when control flow 
        reaches to the caller and yet caller will have 
        address of the freed memory block in its 
        pointer making it a dangling pointer 
    */
}

/* 
    valid from memory perspective but 
    invalid from multi-threading perspective 
*/
int* get_int_3(void)
{
    static int num = 100;
    /* 
        static qualifier has changed the time of allocaton 
        (at the time of building exe not at the time of making a 
        function call), frequency of allocation (only once instead 
        of per function call), lifetime(equal to life time of program
        instead of life time of function call) and storage section 
        (data/bss/lcomm instead of stack)

        Lifetime alteration plays a key role here. 
        Because static variable is not freed at the time of the 
        returning a function, returning its address does not make 
        a caller's pointer a dangling pointer. 
    */
    return (&num);
}


int* get_int_4(void)
{
    int* ptr = NULL;
    ptr = (int*)malloc(sizeof(int));
     // malloc() return value validation 
    return ptr;
}

void get_int_5(int** ppInt)
{
    *ppInt = (int*)malloc(sizeof(int));
    // validate *ppInt
}

