#define OFFSET_OF(T,x)  ((std::size_t)(&((T*)0)->x))
#define CONTAINER_OFFSET(addr,T,x)    ((T*)((std::size_t)addr - OFFSET_OF(T,x)))
struct A
{
        int a; //OFFSET 0
        char b; //OFFSET 4
        float c; //OFFSET 8
};

void test(float* p)//How to access other variable of structure if the address of one variable is given 
{
     // ((struct A*)((std::size_t)p - OFFSET_OF(struct A, c)))->a/b
     //OR
     //CONTAINER_OFFSET(p,T,x)->a/b
     
     // ithe p ha pointer ahe so subtraction he normal subtraction vhava mhnjech pointer arithmetic
     //hou naye mhnun tyala convert kela karan pointer arithmetic ne tyala Float mhnjech 8 ne multiply
     //zala asta(check pointer arithmetic)
}
int main(void)
{
    struct A inA,inB,inC;

    test(&inA.c);
    test(&inB.c);
    test(&inC.c);
    return 0;
}