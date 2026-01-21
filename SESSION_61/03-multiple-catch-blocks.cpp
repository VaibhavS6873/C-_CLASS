#include<iostream>
#include<exception>

void server_function(int N);

int main(void)
{
    try
    {
        int n;
        std::cout<<"Enter an integer:";
        std::cin>>n;
        server_function(n);
    }
    catch(std::range_error& e)
    {
        std::cout<<"range_error:catch block"<<std::endl;
        std::cerr << e.what() <<std::endl;
    }
    catch(std::out_of_range& e)
    {
        std::cout<<"out_of_range:catch block"<<std::endl;
        std::cerr << e.what() <<std::endl;    
    }
    catch(std::overflow_error& e)
    {
        std::cout<<"overflow_error:catch block"<<std::endl;
        std::cerr << e.what() <<std::endl;
    }

    std::cout<<"Client continuing after handling the exception"<<std::endl;
    std::cout<<"Process terminated normally"<<std::endl;
    return 0;
}

void server_function(int N)
{
    if(N < 0)
    {
        throw std::range_error("Negative number is sent");
    }
    else if(N > 0)
    {
        throw std::out_of_range("Positive number is sent");
    }
    else
    {
        throw std::overflow_error("Overflow occured");
    }
}