#include<iostream>
#include<vector>

class Base
{
    private:
        //
    public:
        //
};

class Derived : public Base
{
    private:
        //
    public:
        //
};

void test(Base* pB);

int main(void)
{
    Base* pBase1 = new Base; //Always ok
    Base* pBase2 = new Derived; //ok!
    Derived D;
    Base* pBase3 = &D;

    test(&D);

    delete pBase1;
    pBase1 = 0;

    delete pBase2;
    pBase2 = 0;

    Derived D1, D2, D3;
    Base B1, B2;

    std::vector<Base*> baseVec{&B1, &D1, &D2, &B2, &D3};
    return 0;
}

void test(Base* pB)
{
    //
}
