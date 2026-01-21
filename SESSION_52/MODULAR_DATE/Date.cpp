#include<iostream>
#include "Date.hpp"

        Date::Date(int _day, int _month, int _year):day(_day),month(_month),year(_year){}
        int Date::getDay(){return day;}
        int Date::getMonth(){return month;}
        int Date::getYear(){return year;}
        void Date::setDay(int newDay){day = newDay;}
        void Date::setMonth(int newMonth){month = newMonth;}
        void Date::setYear(int newYear){year = newYear;}
        void Date::show(){std::cout<<day<<"-"<<month<<"-"<<year<<std::endl;}


//Date.cpp -> Date.lib or Date.dll
//Date.cpp -> Date.a or libDate.so