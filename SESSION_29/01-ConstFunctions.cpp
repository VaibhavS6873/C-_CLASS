#include<iostream>

class Date
{
    private:
        int day;
        int month;
        int year;

    public:
        Date(int init_day, int init_month, int init_year): day(init_day),month(init_month),year(init_year)
        {
        }

        int get_day()const //internally it is as int get_day(const Date* this) so you can not modify member of object 
        {                  //in this function
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
    Date myDate(13,4,2025);
    myDate.show();

    const Date* pDate = &myDate;

    myDate.set_day(15); //Date::set_day(&myDate); type(&myDate) == Date*

   // pDate->set_day(20); invalid  Date::set_day(pDate); type(pDate) == const Date*
                        //here set_day accepts Date* but you are giving const Date* which is not allowed
    myDate.get_day(); //allowed here get_day accepts const Date* but you are giving Date* which is allowed

    //inshort you can const Date* should be left hand value and not right hand, 
    //in 1st case it is right hand i.e. Date* = const Date*
    //in 2nd case it is left hand i.e. const Date* = Date*
   return 0;
}

// int n;   // r/w integer 
// const int cnum = 100;    // ronly integer 
// const int* p1 = &n; 
// const int* p2 = &m;  

// const int cnum = 200; 
// int* p = &cnum;          
// const int* p            
// int* const p;            
// const int* const p; 

//                  rw ptr   pointer to const    const pointer   const pointer to pointer to const 
//                  (int*)  (const int*)         (int* const)   const int* const
// pointee(r/w)     1, 1     1, 0                1, 1            1, 0 
// pointer(r/w)     1, 1     1, 1                1, 0            1, 0