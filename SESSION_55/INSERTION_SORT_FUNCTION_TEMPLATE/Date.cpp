#include "Date.hpp"

Date::Date()
{

}

Date::Date(int initDay, int initMonth, int initYear) : day(initDay), month(initMonth), year(initYear)
{

}

bool Date::operator>(const Date& other)
{
    if(this->year > other.year)
        return true;
    else if(this->year < other.year)
        return false;

    if(this->year == other.year)
    {
        if(this->month > other.month)
            return true;
        else if(this->month < other.month )
            return false;
    }

    return this->day > other.day;
}

std::ostream& operator<<(std::ostream& os, const Date& other)
{
    os << other.day << "/" << other.month << "/" <<other.year;
    return os;
}