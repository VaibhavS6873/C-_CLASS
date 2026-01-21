#ifndef _IDATE_HPP
#define _IDATE_HPP

class IDate
{
    public:
        virtual int getDay();
        virtual int getMonth();
        virtual int getYear();
        virtual void setDay(int newDay);
        virtual void setMonth(int newMonth);
        virtual void setYear(int newYear);
        virtual void show();
        static IDate* getInstance(int iniDay, int initMonth, int initYear);
};

#endif //_DATE_HPP 
