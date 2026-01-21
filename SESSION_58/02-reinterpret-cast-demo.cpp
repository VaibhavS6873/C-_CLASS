#include<iostream>
#include<cstdio>

class A
{
    private:
        int num;
        char c;
        float d;
    
    public:
        A() : num(100), c('A'), d(3.14){}

        void f()
        {
            std::cout<< "In A::f()" << std::endl;
        }
};

class B
{
    public:
        void g()
        {
            std::cout<< "In B::g()"<<std::endl;
        }
};

void byteDump(void* p, std::size_t N);

int main(void)
{
    B objB;
    const int num = 100;

    objB.g();
    reinterpret_cast<A*>(&objB)->f();

    A objA;
    byteDump(static_cast<void*>(&objA),sizeof(A));

    return 0;
}

void byteDump(void* p, std::size_t N)
{
    unsigned char* uc = reinterpret_cast<unsigned char*>(p);

    for(std::size_t i = 0; i != N; i++)
    {
        printf("BYTE[%llu]:%hhx\n",i,*(uc+i));  
    }
}