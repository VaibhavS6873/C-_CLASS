#include<iostream>

void endianness(void);
void offsetOf(void);

int main(void)
{
    endianness();
    offsetOf();

    return 0;
}

void endianness(void)
{
    int n =  0x0a0b0c0d;
    
    if(*(char*)(&n) == 0xd)
        std::cout<<"LITTLE ENDIAN"<<std::endl;
    else if(*(char*)(&n) == 0xa)
        std::cout<<"BIG ENDIAN"<<std::endl;
    else
        std::cout<<"STRANGE MACHINE!"<<std::endl;

    /*
        type(n) == int
        type(&n) == int*

        type((char*)&n) == char*
        type(*(char*)&n == char
    */
}

void offsetOf(void)
{
    #define OFFSET_OF(T,x)  ((unsigned long long int)(&((T*)0)->x))
    struct A
    {
        int a; //OFFSET 0
        char b; //OFFSET 4
        float c; //OFFSET 8
    };

    struct A inA;

    std::size_t off_c = (std::size_t)&inA.c - (std::size_t)&inA;
    std::cout<<"offset of member c in struct A using instance:"<<off_c<<std::endl;

    off_c = 0;
    std::cout<<"off_c = " << off_c <<std::endl;

    off_c = (std::size_t)(&((struct A*)0)->c);
    std::cout<<"offset of member c in struct A without using instance:"<<off_c<<std::endl;

     off_c = 0; 
    std::cout << "off_c = " << off_c << std::endl; 

    off_c = OFFSET_OF(struct A, c); 
    std::cout << "off_c = " << off_c << std::endl; 

     /*
        type(inA) == struct A 
        type(inA.c) == float 
        type(&inA.c) == float* 
        type(&inA) == struct A*
    */
}