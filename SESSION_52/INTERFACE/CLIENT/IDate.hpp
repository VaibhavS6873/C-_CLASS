#ifndef _IDATE_HPP
#define _IDATE_HPP

class IDate
{
    public:
        int getDay();
        int getMonth();
        int getYear();
        void setDay(int newDay);
        void setMonth(int newMonth);
        void setYear(int newYear);
        void show();
        static IDate* getInstance(int iniDay, int initMonth, int initYear);
};

#endif //_DATE_HPP 
