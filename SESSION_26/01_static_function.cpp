#include<iostream>

class X
{
    private:
        int p,q,r;
    public:
        X(int _p, int _q, int _r)
        {
            this->p = _p;
            this->q = _q;
            this->r = _r;
        }

        void f1(int x)
        {
            std::cout<<this->p<<" "<<this->q<<" "<<this->r<<std::endl;
            std::cout<<x<<std::endl;
        }

        static int f2(int x)
        {
            //this keyword is syntax error
            //std::cout<<"p:"<<this->p<<endl;
        }
};