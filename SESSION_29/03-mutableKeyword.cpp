#include<iostream>

class Date
{
    private:
        int day;
        int month;
        int year;
        mutable int get_day_counter;

    public:
        Date(int init_day, int init_month, int init_year): day(init_day),month(init_month),year(init_year)
        {
        }

        int get_day()const //internally it is as int get_day(const Date* this) so you can not member of object in this function
        {      
            //get_day() is a non-static member function of classDate which is qualified by const qualifier.

            //As an effect of application of const qualifier the type of implicit 'this' pointer has changed from default Date* to const Date*

            //As a cascading effect of this , no member of object remains modifiable through 'this' pointer within the function

            //Now sometimes,logical requirment dictates that a particular member of an object remain modifiable even within const
            //qualified non-static member function

            //towards this end, we have to use const_cast in order to temporarily change the type of 'this' pointer from const Date*
            // to Date* and after doing so on that one statement we can modify the member we want to modify

            //Because const_cast introduces lot of syntax sugar, C++ asks programmer to qualify such data memebr by keyword mutable
            //(cost_cast is internally managed by compiler)
            
            //this->get_day_counter = this->get_day_counter + 1; //expression must be modifiable value as it is const Date* this    
            get_day_counter = get_day_counter + 1;
            return day;
        }

        int get_month()const
        {
            return month;
        }

        int get_year()const
        {
            return year;
        }

        int get_get_day_counter()const
        {
            return get_day_counter;
        }

        void set_day(int newDay) //void set(Date* this, int newDay)
        {
            day = newDay; 
        }

        void setMonth(int newMonth)
        {
            month = newMonth;
        }

        void setYear(int newYear)
        {
            year = newYear;
        }

        void show() const
        {
            std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
        }
};

int main(void)
{
    Date myDate(14,4,2025);

    for(int i = 0; i<5;i++)
    {
        int day = myDate.get_day();
    }

    std::cout<<"get_day_counter:"<<myDate.get_get_day_counter()<<std::endl;
   return 0;
}