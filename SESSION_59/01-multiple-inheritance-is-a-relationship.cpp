#include<cstdio>
#include<cstring>

class B1
{
    private:
        int num1,num2;
    public:
        B1(): num1(100),num2(200){}

        void f()
        {
            puts("B1::f()");
            printf("num1 = %d, num2 = %d\n",num1,num2);
        }
};

class B2
{
    private:
        double d1,d2;
    public:
        B2():d1(100.101),d2(200.202){}

        void f()
        {
            puts("B2::f()");
            printf("d1 = %.3lf, d2 = %.3lf\n,d1,d2");
        }

};

class D : public B1, public B2
{
    private:
        int a[4];
    public:
        D() : B1(),B2(){
            memset(reinterpret_cast<void*>(a),0,4*sizeof(int));
        }

        void g()
        {
            puts("D::g()");
        }
};

int main(void)
{
    D objD;

    printf("sizeof(B1)=%zu, sizeof(B2)=%zu, sizeof(D)=%zu\n",sizeof(B1),sizeof(B2),sizeof(D));

    //objD.f();
    objD.B1::f();
    objD.B2::f();

    D* pD = &objD;

    pD->B1::f();
    pD->B2::f();

    printf("&objD = %zu\n",reinterpret_cast<std::size_t>(&objD));

    printf("dynamic_cast<B1*>(&objD) = %zu\n",reinterpret_cast<std::size_t>(dynamic_cast<B1*>(&objD)));

    printf("dynamic_cast<B2*>(&objD) = %zu\n",reinterpret_cast<std::size_t>(dynamic_cast<B2*>(&objD)));

    return 0;
}