#include<iostream>

class Date
{
    private:
        int day, month, year;
        std::size_t getterCounter;

    public:
        Date():day(1), month(1), year(1970), getterCounter(0)
        {}

        int getDay()const
        {
            const_cast<Date*>(this)->getterCounter += 1;
            return day;
        }

        int getMonth()const
        {
            const_cast<Date*>(this)->getterCounter += 1;
            return month;
        }

        int getYear()const
        {
            const_cast<Date*>(this)->getterCounter += 1;
            return year;
        }

        std::size_t getGetterCount()const
        {
            return getterCounter;
        }

};

void test(void);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    const int num = 100;
    int* p = 0;

    p = const_cast<int*>(&num);

    std::cout<<"Before:"<<*p<<std::endl;
    *p = 500;
    std::cout<<"After:"<<*p<<std::endl;
}
