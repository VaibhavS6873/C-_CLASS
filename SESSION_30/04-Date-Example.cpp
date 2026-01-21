#include<iostream>

class Date
{
    private:
        int day,month,year;
    public:
        Date(int init_day,int init_month, int init_year):day(init_day),month(init_month),year(init_year)
        {
            std::cout<<"Date created"<<std::endl;
        }

        void set(int _dd, int _mm, int _yy)
        {
            day = _dd;
            month = _mm;
            year = _yy;
        }

        void show()const
        {
            std::cout<<day<<"/"<<month<<"/"<<year<<std::endl;
        }
};

Date& getNewDate(int dd, int mm, int yy);

void triggerMethods(const Date& ref);

const Date& getNewInstance(int dd, int mm, int yy);


int main(void)
{
    Date myDate_1(1,1,1970);
    myDate_1.show();

    Date* pDate = new Date(1,1,1970);
    pDate->show();
    delete pDate;
    pDate = 0;

    Date& refDate = *(new Date(19,4,2025));
    refDate.show();
    delete &refDate;

    Date& refDate_1 = getNewDate(19,4,2025);
    refDate_1.set(20,5,2026);
    refDate_1.show();
    delete &refDate_1;

    const Date& refDate_2 = getNewInstance(19,4,2025);
    //refDate_2.set(20,5,2026); //this will cause error as it is const and set fun accepts non-const object
    refDate_2.show();
    delete &refDate_2;
    return 0;
}

Date& getNewDate(int dd, int mm, int yy)
{
    return *(new Date(dd,mm,yy));
    /*
        above code is equivalent to the following 
        Date* pDate = new Date(dd, mm, yy); 
        return *pDate;
    */
}

void triggerShow(const Date& ref)
{
    ref.show();
    //ref.set(20,5,2026); CTE
}

const Date& getNewInstance(int dd, int mm, int yy)
{
    return *(new Date(dd,mm,yy));
}