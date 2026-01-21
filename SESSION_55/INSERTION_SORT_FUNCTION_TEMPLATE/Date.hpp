#ifndef _DATE_HPP
#define _DATE_HPP

#include<iostream>

class Date
{
    private:
        int day,month,year;

    public:
        Date();
        Date(int,int,int);
        bool operator>(const Date& other);
        friend std::ostream& operator<<(std::ostream& os, const Date& other);
};

#endif  