#include<iostream>

class Date
{
    private:
        int day;
        int month;
        int year;
    public:
        Date(int init_day, int init_month, int init_year):day(init_day),month(init_month),year(init_year)
        {
            // so far we had used the following syntax (explicit assignment)
            // this->day = init_day; 
            // this->month = init_month; 
            // this->year = init_year; 
        }
        void show()
        {
            std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
        }
};

int main(void)
{
    Date myDate(12, 4, 2025); 

    myDate.show(); 

    return 0;
}