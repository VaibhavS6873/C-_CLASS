#include<iostream>
#include "smart_ptr.hpp"

class Date
{
    private:
        int dd, mm, yy;
    public:
        Date(int _dd, int _mm, int _yy) : dd(_dd), mm(_mm), yy(_yy)
        {

        }

        ~Date()
        {
            std::cout<<"In Dtor of Date"<<std::endl;
        }

        void show()const
        {
            std::cout<< dd <<"/"<<mm<<"/"<<yy<<std::endl;
        }

};

void test(void);

int main(void)
{
    std::cout<<"CPA::smart_ptr"<<std::endl;
    test();
    return 0;
}

void test(void)
{
    int n;
    cpa::smart_ptr<int>pint(new int(100));

    std::cout<< *pint<< std::endl;
    *pint = 200;
    std::cout<< *pint<< std::endl;

    cpa::smart_ptr<Date>pDate(new Date(19,10,2024));
    pDate->show();
}