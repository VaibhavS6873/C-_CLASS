#ifndef _IDATE_HPP
#define _IDATE_HPP

class IDate
{
    public:
        virtual int getDay() = 0;
        virtual int getMonth() = 0;
        virtual int getYear() = 0;
        virtual void setDay(int newDay) = 0;
        virtual void setMonth(int newMonth) = 0;
        virtual void setYear(int newYear) = 0;
        virtual void show() = 0;
        static IDate* getInstance(int iniDay, int initMonth, int initYear);
};

#endif //_DATE_HPP 
