#ifndef _DATE_HPP
#define _DATE_HPP

#include<iostream>
#include "IDate.hpp"
class Date : public IDate
{
    private:
        int day, month, year;

    public:
        Date(int _day, int _month, int _year);
        int getDay();
        int getMonth();
        int getYear();
        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);
        void show();
};

#endif //_DATE_HPP 
