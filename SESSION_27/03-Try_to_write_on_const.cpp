#include<iostream>

const int gc_num = 100;

int main(void)
{
    const int lc_num = 200;
    int* ptr1 = 0;
    int* ptr2 = 0;

    static const int x = 3000; //hyala stack madhe jaga na milta RODATA madhe milte
     // Write an experiment to prove 
    // that x goes into read only data section 
    // because of static qualifier 
    // how to prove it? load address of x 
    // into ptr1 or ptr2 using const_cast 
    // and try to modify it 
    // if you get segault(linux), bus error(mac)
    // nothing on windows -> proved 


   /* gc_num = 1000;
    lc_num = 2000;
    ptr1 = &gc_num; //C++ hych thikani error deto.
    ptr2 = &lc_num */

    //but apan c++ madhe explicit typecast ne karu shakto
    ptr2 = const_cast<int*>(&lc_num);
    std::cout<<"Before *ptr = 2000:(display via *ptr2):"<<*ptr2<<std::endl;
    *ptr2 = 2000;
    std::cout<<"After *ptr = 2000:(display via *ptr2):"<<*ptr2<<std::endl;

    std::cout<<"Before *ptr = 20000:(display via lc_num):"<<lc_num<<std::endl; //work as symbolic const
    *ptr2 = 20000;
    std::cout<<"After *ptr = 20000:(display via lc_num):"<<lc_num<<std::endl;
    std::cout<<"After *ptr = 20000:(display via *ptr2):"<<*ptr2<<std::endl;

    ptr2 = const_cast<int*>(&x);
    std::cout<<"Before *ptr = 4000:(display via *ptr2):"<<*ptr2<<std::endl;
    *ptr2 = 4000; //segmenatation fault because it has space on the RODATA and not on stack
    std::cout<<"After *ptr = 4000:(display via *ptr2):"<<*ptr2<<std::endl;
    
    return 0;
}