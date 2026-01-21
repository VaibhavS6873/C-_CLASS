#include<iostream>
#include<memory>

class Date
{
    private:
        int dd, mm, yy;
    public:
        Date(int _dd, int _mm, int _yy):dd(_dd),mm(_mm),yy(_yy)
        {

        }

        ~Date()
        {
            std::cout<<"In Dtor of Date"<<std::endl;
        }

        void show()const{
            std::cout<<dd<<"/"<<mm<<"/"<<yy<<std::endl;
        }
};

void test(void);

int main(void)
{
    std::cout<<"std::auto_ptr"<<std::endl;
    test();
    return 0;
}

void test(void)
{
    int n;
    //std::auto_ptr<int>pint(new int(100));
   // std::cout<<*pint<<std::endl;
   // *pint = 200;
    //std::auto_ptr<Date>pDate(new Date(19,20,2024));
    //pDate->show();
}