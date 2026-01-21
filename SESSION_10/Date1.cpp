#include<iostream>
using std::cout;
using std::endl;

class Date
{
    public:
        int day;
        int month;
        int year;

        void show()
        {
            cout<<"Address of object used for making the current call" << this <<endl;
            cout<<this->day << "/" << this->month << "/" << this->year <<endl;
        }
};

int main(void)
{
    Date d1;
    Date d2;
    Date d3;

    //setting day month year for d1;
    d1.day = 1;
    d1.month = 10;
    d1.year = 1999;

    //setting day month year for d2;
    d2.day = 10;
    d2.month = 12;
    d2.year = 1973;

    //setting day month year for d3;
    d3.day = 3;
    d3.month = 12;
    d3.year = 1991;
    
    cout<<"main():Making use of object 'd1' to make call to Date::show()"<<endl;
    cout<< "main():Address of object 'd1' is : "<<&d1<<endl;
    d1.show(); //Date::show(&d1);

    cout<<"main():Making use of object 'd2' to make call to Date::show()"<<endl;
    cout<< "main():Address of object 'd2' is : "<<&d1<<endl;
    d2.show();

    cout<<"main():Making use of object 'd3' to make call to Date::show()"<<endl;
    cout<< "main():Address of object 'd3' is : "<<&d1<<endl;
    d3.show();
    return (0);
}