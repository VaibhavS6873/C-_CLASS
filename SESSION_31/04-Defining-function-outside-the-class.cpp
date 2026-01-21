#include<iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int, int, int);
        int getDay()const;
        int getMonth()const;
        int getYear()const;
        void setDay(int newDay);
        void setMonth(int newYear);
        void setYear(int newYear);
        void show()const;
};

Date::Date(int init_day, int init_month, int init_year): day(init_day),month(init_month),year(init_year)
{

}
int Date::getDay()const
{
    return day;
}

int Date::getMonth()const
{
    return month;
}

int Date::getYear()const
{
    return year;
}

void Date::setDay(int newDay)
{
    day = newDay;
}


void Date::setMonth(int newMonth)
{
    month = newMonth;
}

void Date::setYear(int newYear)
{
    year = newYear;
}

void Date::show()const
{
    std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
}
int main(void)
{
    //create and use Date object
    Date myDate(1,1,1970);
    myDate.show();
    return 0;
}
