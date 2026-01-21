#include <iostream> 
#include <cstdlib> 

class Date{
    private: 
        int day; 
        int month; 
        int year; 

    public: 
        // constructor is implemented but have not been called 
        // after dynamically allocating Date object using malloc() 
        Date(int init_day, int init_month, int init_year){
            std::cout << "----Entered Date::Date()-----" << std::endl; 
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
            std::cout << "----Leaving Date::Date()-----" << std::endl; 
        }

        void init(int init_day, int init_month, int init_year){
            std::cout << "----Entered Date::init()-----" << std::endl; 
            this->day = init_day; 
            this->month = init_month; 
            this->year = init_year; 
            std::cout << "----Leaving Date::init()-----" << std::endl; 
        }

        void show(){
            std::cout << day << "/" << month << "/" << year << std::endl; 
        }
}; 

int main(void)
{
    Date* pDate = (Date*)malloc(sizeof(Date)); 
    if(NULL == pDate)
    {
        std::cout << "Error" << std::endl; 
        exit(-1); 
    }

    pDate->init(16, 3, 2025); 
    pDate->show(); 

    free(pDate); 
    pDate = NULL; 

    return (0); 
}


// This code shows us that using malloc() / free() for dynamic 
// memory management does not allow atomic execution of memory allocation 
// and initialization. Therefore the advantage of constructor feature 
// is nullified. 

// Moreover we are looking at an ugly design situation wherein 
// constructor works for only data definition statements 
// and not for objects allocated dynamically. 

// Therefore C++ designed an operator named 'new' to allow C++ programmers 
// to allocate object at run time. 

// as syntax of operator is decided by programming language, C++ incorporated 
// the specification of initialization data in the syntax 
/// e.g. to allocate and initialize Date object at run time -> programmer can write 
//  new Date(dd, mm, yy); 

// compilation of this statement also belongs to programming language, C++ compilers 
// can generate assembly code which call mem allocation function and construtor in tandem 
// to ensure allocation + initalization atomicity. 

