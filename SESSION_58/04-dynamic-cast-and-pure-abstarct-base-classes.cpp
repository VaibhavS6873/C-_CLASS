#include<iostream>
#include<cstdio>

class I1
{
    public:
        virtual void f1() = 0;
        virtual void f2() = 0;
};

class I2
{
    public:
        virtual void g1() = 0;
        virtual void g2() = 0;
        virtual void g3() = 0;
};

class I3
{
    public:
        virtual void h1() = 0;
        virtual void h2() = 0;
        virtual void h3() = 0;
        virtual void h4() = 0;
};

class D : public I1, public I2, public I3
{
    private:
        int num1,num2,num3,num4;

    public:
        ///////////////////////
        void f1() {}
        void f2() {}
       /////////////////////////

       void g1() {}
       void g2() {}
       void g3() {}

        /////////////////////////
       void h1() {}
       void h2() {}
       void h3() {}
       void h4() {}
     ////////////////////
};

int main(void)
{
    D objD;

    printf("dynamic_cast<I1*>(&objD) = %llu\n",
            reinterpret_cast<std::size_t>(dynamic_cast<I1*>(&objD)));

    
     printf("dynamic_cast<I2*>(&objD) = %llu\n",
            reinterpret_cast<std::size_t>(dynamic_cast<I2*>(&objD)));

     printf("dynamic_cast<I3*>(&objD) = %llu\n",
            reinterpret_cast<std::size_t>(dynamic_cast<I3*>(&objD)));
}