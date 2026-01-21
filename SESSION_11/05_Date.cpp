#include<iostream>

using std::cout;
using std::endl;


// server side -> start
class Date
{
    //data layout defination
    private:
        int day;
        int month;
        int year;

    public:
        //REMEMBER-> First parameter of init() function is Date* this
        void init(int init_day, int init_month, int init_year)
        {
            this->day = init_day;
            this->month = init_month;
            this->year = init_year;
        }

        //REMEMBER-> First parameter of show() function is Date* this
        void show()
        {
            cout<< this->day<<"/"<<this->month<<"/"<<this->year<<endl;
        }
};
// server side -> end

//client side -> start
int main(void)
{
    Date myDate;

    cout<<"myDate object before calling init() function on it"<<endl;
    myDate.show();
    myDate.init(8, 2, 2025); // Date::init(&myDate , 8 , 2 , 2025)
    cout<<"myDate object after calling init() function on it"<<endl;
    myDate.show();

    return 0;
}