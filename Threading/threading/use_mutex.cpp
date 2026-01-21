#include<iostream>
#include<unistd.h>
#include "thread.hpp"

int shared_data = 0;

void* common_entry(void* args);

int main(void)
{
    cpa::thread th1(common_entry), th2(common_entry);
    th1.run();
    th2.run();
    th1.join();
    th2.join();
    return 0;
}

void* common_entry(void* args)
{
    static cpa::mutex mu;
    while(true)
    {
        mu.lock();
        std::cout<<"shared data:"<<++shared_data<<std::endl;
        mu.unlock();
    }
}