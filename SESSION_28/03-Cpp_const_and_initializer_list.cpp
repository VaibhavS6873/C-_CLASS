#include<iostream>

class Test
{
    private:
        int x;
        const int num;

    public:
        Test(int init_x, int init_num):num(init_num)
        {
            x = init_x;
        }
};

class Base
{
    private:
        int n1,n2;
    public:
        Base(int _n1, int _n2):n1(_n1),n2(_n2)
        {

        }
};

class Derived: public Base
{
    private:
        float f1,f2;
    public:
         Derived(float _f1, float _f2, int _n1, int _n2) : Base(_n1, _n2)
        {
            f1 = _f1; 
            f2 = _f2; 
        }
};