#include<iostream>
#include<exception>

void server_function(int N);

int main(void)
{
    server_function(100);   //works
    server_function(-100); //an exception willbe triggered by server_function()
                           //as a client we have not done anything to handle the exception
                           //therefore, this is a case of unhandled exception and it will
                           //result in abnormal termination of process

    std::cout<<"Process terminated normally"<<std::endl;
    return 0;
}

void server_function(int N)
{
    if(N < 0)
    {
        throw std::runtime_error("Negative number is sent");
    }
    else
    {
        std::cout<<"Server side operation on non-negative number will be performed"<<std::endl;
    }
}