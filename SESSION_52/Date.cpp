#include<iostream>

class Date
{
    private:
        int day, month, year;

    public:
        Date(int _day, int _month, int _year):day(_day),month(_month),year(_year){}
        int getDay(){return day;}
        int getMonth(){return month;}
        int getYear(){return year;}
        int setDay(int newDay){day = newDay;}
        int setMonth(int newMonth){month = newMonth;}
        int setYear(int newYear){year = newYear;}
        void show(){std::cout<<day<<"-"<<month<<"-"<<year<<std::endl;}

};

//Date.cpp -> Date.lib or Date.dll
//Date.cpp -> Date.a or libDate.so