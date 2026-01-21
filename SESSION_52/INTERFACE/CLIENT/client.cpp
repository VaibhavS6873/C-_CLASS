#include<iostream>
#include "IDate.hpp"

int main(void)
{
    IDate* pIDate = IDate::getInstance(12,7,2025);

    std::cout << "pIDate->show()"<<std::endl;
    pIDate->show();

    std::cout<<"EXECUTING:pIDate->IDate::show():" << std::endl; 
    pIDate->IDate::show(); //flaw in the plan #1

    std::cout<<"EXECUTING:IDate* pIDate1 = new IDate" << std::endl;
    IDate* pIDate1 = new IDate; //Flaw in the plan #2
    delete pIDate1;
    pIDate1 = 0;
    std::cout<<"Done deleting pIDate1"<<std::endl;

    delete pIDate;
    pIDate = 0;

    return 0;                                                                                                   

}

//Also include Date.lib in the directory