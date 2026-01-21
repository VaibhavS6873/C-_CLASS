#include<iostream>
 using std::cin;
 using std::cout;


 class Date
 {
    public:
         typedef int day_t;
         typedef int month_t;
         typedef int year_t;

    private:
        day_t day;
        month_t month;
        year_t year;

    public: 
        Date(day_t init_day, month_t init_month, year_t init_year)
        {
            day = init_day;
            month = init_month;
            year = init_year;
        }

        day_t get_day()
        {
            return day;
        }

        month_t get_month()
        {
            return month;
        }

        year_t get_year()
        {
            return year;
        }

 };

 int main(void)
 {
    Date myDate(15,2,2025);

   Date::day_t day =  myDate.get_day();
   Date::month_t month = myDate.get_month();
   Date::year_t year = myDate.get_year();

   cout<<day<<"/"<<month<<"/"<<year;
    return 0;
 }