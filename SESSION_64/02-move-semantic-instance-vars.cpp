#include<iostream>
#include<cstring>

class Date
{
    private:
        int day, month, year;
    public:
        Date(int init_day, int init_month, int init_year) : day(init_day), month(init_month), year(init_year)
        {

        }

        Date(const Date& other)
        {
            std::cout<<"Date::Date(const Date& other):In Copy Constructor"<<std::endl;
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
        }

        Date& operator=(const Date& other)
        {
            std::cout<<"Date& operator=(const Date& other):In Copy Assignment operator"<<std::endl;
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;
            return *this;
        }

        Date(Date&& other)
        {
            std::cout<<"Date::Date(Date&& other):In move constructor"<<std::endl;
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;

            memset(reinterpret_cast<void*>(&other),0,sizeof(Date));
        }

        Date& operator=(Date&& other)
        {
            std::cout<<"Date& operator=(Date&& other):In move assignment operator"<<std::endl;
            this->day = other.day;
            this->month = other.month;
            this->year = other.year;

            memset(reinterpret_cast<void*>(&other),0,sizeof(Date));
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& dateObject)
        {
            os<<dateObject.day<<"/"<<dateObject.month<<"/"<<dateObject.year<<std::endl;
            return os;
        }
};

int main(void)
{
    Date D1(23,8,2025);
    Date D2(D1);    //via copy constructor

    std::cout<<"After initializing D2 by D1 via copy constructor"<<std::endl;
    std::cout<<"D1:"<<D1<<std::endl;    //23/8/2025
    std::cout<<"D2:"<<D2<<std::endl;    //23/8/2025

    Date D3(24,8,2025);
    std::cout<<"Before initializing D4 by moving D3 into it via move constructor"<<std::endl;
    std::cout<<"D3:"<<D3<<std::endl;

    Date D4(std::move(D3));

    std::cout<<"After initializing D4 by moving D3 into via move constructor"<<std::endl;
    std::cout<<"D4:"<<D4<<std::endl;    //24/8/2025
    std::cout<<"D3:"<<D3<<std::endl;

    return 0;
}