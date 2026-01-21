#include<iostream>

class CPA_int
{
    private:
        int n;
    public:
        CPA_int(int _n) : n(_n){}

        void show()const
        {
            std::cout<<"internal n:"<<n<<std::endl;
        }

        CPA_int& operator++() //for pre increment
        {
            this->n = this->n + 1;
            return *this;
        }

        CPA_int operator++(int) //for post increment and their is no any meaning of int here.It is just for the syntax
        {
            CPA_int tmp(this->n);
            this->n = this->n + 1;
            return tmp;
        }
};

int main(void)
{
    CPA_int X(10);
    CPA_int result(0);

    //++X;
    //result = ++X //CPA_int::operator++(&X)
    result = X++;
    return 0;
}