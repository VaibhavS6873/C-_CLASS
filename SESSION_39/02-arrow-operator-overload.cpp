#include<iostream>

class Date
{
    private:
        int day, month, year;
    public:
        Date(int _day = 1, int _month = 1, int _year = 1970): day(_day),month(_month),year(_year)
        {
        }

        int getDay()const
        {
            return day;
        }

        int getMonth()const{
            return month;
        }

        int getYear()const{
            return year;
        }

        void setDay(int newDay)
        {
            day = newDay;
        }

        void setMonth(int newMonth)
        {
            month = newMonth;
        }

        void setYear(int newYear)
        {
            year = newYear;
        }

        void show()const
        {
            std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
        }
};

class DatePtr
{
    private:
        Date* pDate;

    public:
        DatePtr(Date* _pDate) : pDate(_pDate)
        {
            std::cout<<"----Entered DatePtr::datePtr()----"<<std::endl;
            std::cout<<"Leaving DatePtr::DatePtr()----"<<std::endl;
        }

        ~DatePtr()
        {
            std::cout<<"----Entered DatePtr::~DatePtr()----"<<std::endl;
            delete pDate;
            pDate = 0;
            std::cout<<"Leaving DatePtr::~DatePtr()----"<<std::endl;
        }

        Date* operator->()
        {
            return this->pDate;
        }
};

void test1(void);
void test2(void);

int main(void)
{
    test1();
    test2();
    return 0;
}

void test1(void)
{
    Date* pDate = new Date;

    pDate->setDay(24);
    pDate->setMonth(5);
    pDate->setYear(2025);

    delete pDate;
    pDate = 0;
}

void test2(void)
{
    DatePtr ptrToDate(new Date);

    int dd = ptrToDate->getDay();
    int mm = ptrToDate->getMonth();
    ptrToDate->show();
}


