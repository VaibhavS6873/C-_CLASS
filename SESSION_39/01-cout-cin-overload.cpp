#include<iostream>

class Date
{
    friend std::ostream& operator<<(std::ostream& os, const Date& refDate);
    friend std::istream& operator>>(std::istream& is, const Date& refDate);
    private:
        int day,month,year;

    public:
        Date(int _day = 1, int _month = 1, int _year = 1970):day(_day),month(_month),year(_year)
        {} 
};


void test1(void);
void test2(void);
int main(void)
{
    test1();
    test2();
    return 0;
}

std::ostream& operator<<(std::ostream& os, const Date& refDate)
{
    os << refDate.day << "/" << refDate.month << "/" << refDate.year << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, const Date& refDate)
{
    std::cout<<"Enter day:";
    is >> refDate.day;
    std::cout<<"Enter month:";
    is >> refDate.month;
    std::cout<<"Enter year:";
    is >> refDate.year;
    return is;


}

void test1(void)
{
    Date myDate;

    std::cout<<"----Entered test1()----"<<std::endl;
    std::cin>>myDate;
    std::cout<<myDate;
    std::cout<<"----Exited test1()----"<<std::endl;
}

void test2(void)
{
    Date myDate1, myDate2;

    std::cout<<"----Entered test2()----"<<std::endl;
    std::cin>>myDate1>>myDate2;
    std::cout<<myDate1<<myDate2;
    std::cout<<"----Exited test2()----"<<std::endl;
}