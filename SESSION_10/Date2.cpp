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

    //Define three pointers to class Date
    Date* pDate1 = 0;
    Date* pDate2 = 0;
    Date* pDate3 = 0;

    pDate1 = &d1;      
    pDate2 = &d2;
    pDate3 = &d3;
    //setting day month year for d1;
    pDate1->day = 1;
    pDate1->month = 10;
    pDate1->year = 1999;

    //setting day month year for d2;
    pDate2->day = 10;
    pDate2->month = 12;
    pDate2->year = 1973;

    //setting day month year for d3;
    pDate3->day = 3;
    pDate3->month = 12;
    pDate3->year = 1991;
    
    cout<<"main():Making use of pointer pDate1 to make call to Date::show()"<<endl;
    cout<< "main():Address of object 'd1' is : "<<&d1<<endl;
    pDate1->show();  //Date::show(pDate1);

    cout<<"main():Making use of pointer pDate2  to make call to Date::show()"<<endl;
    cout<< "main():Address of object 'd2' is : "<<&d1<<endl;
    pDate2->show();

    cout<<"main():Making use of pointer pDate3 to make call to Date::show()"<<endl;
    cout<< "main():Address of object 'd3' is : "<<&d1<<endl;
    pDate3->show();
    return (0);
}