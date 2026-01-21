#include<iostream>

void swap(int& var1, int& var2);

int main(void)
{
    int n1 = 100;
    int n2 = 200;

    std::cout<<"Before:n1:"<<n1<<",n2:"<<n2<<std::endl;
    swap(n1,n2);
    std::cout<<"After:n1:"<<n1<<",n2:"<<n2<<std::endl;
    return 0;
}

void swap(int& ref1, int& ref2)
{
    int tmp;
    
    tmp = ref1;
    ref1 = ref2;
    ref2 = tmp;
}

/*
Date myDate = new Date;
myDate = null;
myDate = new Date;

Date mySecondDate = myDate;

myDate = NULL;
mySecondDate = null;

T ref;
T* p;
T* const p;
*/