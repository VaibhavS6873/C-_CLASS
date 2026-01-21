#include <iostream> 
#include <cstdlib> 

class Date{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
    
        Date(int init_day, int init_month, int init_year){
            std::cout << "----Entered Date::Date()-----" << std::endl; 
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
            std::cout << "----Leaving Date::Date()-----" << std::endl; 
        }


        void show(){
            std::cout << day << "/" << month << "/" << year << std::endl; 
        }
}; 

// new = malloc() + automatic call to constructor 
// delete = automatic call to destructor + free() 
int main(void)
{
    Date* pDate = NULL;
    pDate = new Date(22, 3, 2025);

    pDate->show();
    free(pDate);
    pDate = NULL;

    return 0;
}