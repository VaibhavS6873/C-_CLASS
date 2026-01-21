#include<iostream>
using std::cout;
using std::endl;

class Date
{
    private:
        int day;
        int month;
        int year;

        public:
            //Constructor function
            Date(int _day , int _month , int _year)
            {
                cout<<"**********DATE CONSTRUCTOR ENTER************"<< endl;
                cout<<"Address of newly allocated object = "<< this <<endl;
                this->day = _day;
                this->month = _month;
                this->year = _year;
                cout<<"**********DATE CONSTRUCTOR LEAVE************"<< endl;
            }

            void show()
            {
                cout<<"Date::show() Enter"<<endl;
                cout<<"Address of object whose members must be shown = "<< this <<endl;
                cout<< day << "/" << month << "/" << year << endl;
                cout<<"Date::show() Leave"<< endl;
            }
};

int main(void)
{
    Date myBirthdate( 1 , 10, 1999);
    //12 bytes of memory block will be allocated to Date object
    //Make call to Date::Date(addr_of_new_object, 9, 2, 2025)
    Date cpaBirthDate(1, 12, 2009);

    cout<<"main()::address of myBirthdate:"<<&myBirthdate << endl;
    cout << "main()::address of cpaBirthdate:"<<&cpaBirthDate<<endl;

    myBirthdate.show(); 
    cpaBirthDate.show();
    return 0;
}