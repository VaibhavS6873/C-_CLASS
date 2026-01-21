#include<iostream>
#include<exception>

class my_error:public std::runtime_error
{
    public:
        my_error(const char* msg) : std::runtime_error(msg)
        {

        }
};

void my_function(int);

int main(void)
{
    try
    {
        my_function(-100);    
    }
    catch(my_error& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}


void my_function(int N)
{
    if(N < 0)
        throw my_error("Exception my_error: Negative number sent");
}

/*
namespace std
{
	class exception
	{
	private:
		const char* error_msg;
	public:
		exception(const char* msg) : error_msg(msg) {}

		virtual const char* what() const
		{
			return error_msg;
		}
	};
	
	class runtime_error : public exception
	{
	public: 
		runtime_error(const char* msg) : exception(msg) {} 
	};
} 

class my_error : public std::runtime_error
{
public: 
	my_error(const char* msg) : std::runtime_error(msg)
	{
	}
};


throw my_error("something went wrong"); 

class stack_full_error : public std::overflow_error 
{
	public: 
		stack_full_error(const char* msg) : std::overflow_error(msg)
		{
		}
}; 

class stack_empty_error : public std::underflow_error
{
	public:
		stack_empty_error(const char* msg) : std::underflowflow_error(msg)
		{
		}
};

*/