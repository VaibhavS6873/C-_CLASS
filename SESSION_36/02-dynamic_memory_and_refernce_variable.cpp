#include<iostream>
#include<cstdlib>

struct Date
{
    int day, month, year;
};

struct Date& getDateInstance(void);
void initDateInstance(struct Date& refDate, int init_day, int init_month, int init_year);
void showDateInstance(struct Date& refDate);
void releaseDateInstance(struct Date& refDate);

int main(void)
{
    struct Date& refDate = getDateInstance();
    initDateInstance(refDate, 10,5,2025);
    showDateInstance(refDate);
    releaseDateInstance(refDate);
    return 0;
}

struct Date& getDateInstance(void)
{
    struct Date* pDate = NULL;

    pDate = new Date;
    if(0 == pDate)
    {
        std::cerr<<"getDateInstance():malloc():fatal:out of memory"<<std::endl;
        exit(EXIT_FAILURE);
    }

    return (*pDate);
}

void initDateInstance(struct Date& refDate, int init_day, int init_month, int init_year)
{
    refDate.day = init_day;
    refDate.month = init_month;
    refDate.year = init_year;
}

void showDateInstance(struct Date& refDate)
{
    std::cout<< refDate.day << "/" << refDate.month << "/" <<refDate.year << std::endl;
}

void releaseDateInstance(struct Date& refDate)
{
    delete &refDate;
}