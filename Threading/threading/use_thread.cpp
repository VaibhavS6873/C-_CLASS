#include<iostream>
#include "thread.hpp"

void* thread_entry_1(void*);
void* thread_entry_2(void*);

int main(void)
{
    cpa::thread th1(thread_entry_1);
    cpa::thread th2(thread_entry_2);

    th1.run();
    th2.run();

    th1.join();
    th2.join();

    return(EXIT_SUCCESS);
}

void* thread_entry_1(void* args)
{
    while(true)
    {
        std::cout<<"thread 1"<<std::endl;
    }
}

void* thread_entry_2(void* args)
{
    while(true)
    {
        std::cout<<"thread 2"<<std::endl;
    }
}

