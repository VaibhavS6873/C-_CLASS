#include<cstdio>
#include<iostream>

class B
{
    private:   
        int num1,num2;
    public:
        B():num1(100), num2(200){}

        void f()
        {
            puts("In B::f()");
            printf("num1 = %d, num2 = %d\n",num1,num2);
        }
};

class D1 : virtual public B
{
    private:
        double d1, d2;
    public:
        void g1()
        {
            puts("D1::g1()");
        }
};

class D2 : virtual public B
{
    private:
        double d3,d4;
    public:
        void g2()
        {
            puts("In D2::g2()");
        }
};

class D : public D1, public D2
{
    private:
        int a[4];
    public:
        void h()
        {
            puts("D::h()");
        }
};

int main(void)
{
    D objD;

    printf("sizeof(B) = %zu\n", sizeof(B));
    printf("sizeof(D1) = %zu\n",sizeof(D1));
    printf("sizeof(D2) = %zu\n", sizeof(D2));
    printf("sizeof(D) = %zu\n",sizeof(D));

    printf("address of objD = %zu\n", reinterpret_cast<std::size_t>(&objD));
    printf("Address of instance of B inside D1:%zu\n",reinterpret_cast<std::size_t>(dynamic_cast<B*>(dynamic_cast<D1*>(&objD))));

    printf("Address of instance of B inside D2:%zu\n",reinterpret_cast<std::size_t>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))));

    printf("num1 in instance of B in D2:%d\n",*reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))));

    printf("num2 in instance of B in D2:%d\n",*reinterpret_cast<int*>((reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))) +1)));    

    *reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))) = 1000;

    *reinterpret_cast<int*>((reinterpret_cast<int*>(dynamic_cast<B*>(dynamic_cast<D2*>(&objD))) +1)) = 2000;

    (dynamic_cast<B*>(dynamic_cast<D1*>(&objD)))->f();
    (dynamic_cast<B*>(dynamic_cast<D2*>(&objD)))->f();

    objD.f();

    D1 objD1;

    return 0;
}