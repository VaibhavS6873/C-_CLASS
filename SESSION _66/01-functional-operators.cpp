#include<iostream>
#include<functional>

class complex
{
    private:
        double re, im;
    public:
        complex() : re(0.0), im(0.0){}

        complex(double _re, double _im) : re(_re), im(_im){}

        complex operator+(const complex& other)const
        {
            return complex(this->re + other.re,this->im + other.im);
        }

        
        complex operator-(const complex& other)const
        {
            return complex(this->re - other.re,this->im - other.im);
        } 

        friend std::ostream& operator<<(std::ostream& os, const complex& c)
        {
            os<<"("<<c.re<<")+i("<<c.im<<")";
            return os;
        }
};

void test_complex_oo_syntax(void);
void test_complex_functional_syntax(void);

int main(void)
{
    test_complex_oo_syntax();
    test_complex_functional_syntax();
    return 0;
}

void test_complex_oo_syntax(void)
{
    std::cout<<"----Entered test_complex_oo_syntax----"<<std::endl;
    complex c1(1.1,4.5);
    complex c2(3.4,5.6);

    complex c_sum = c1 + c2;
    complex c_sub = c1 - c2;

    std::cout<<"c1:"<<c1<<std::endl;
    std::cout<<"c2:"<<c2<<std::endl;
    std::cout<<"c_sum:"<<c_sum<<std::endl;
    std::cout<<"c_sub:"<<c_sub<<std::endl;

    std::cout<<"----leaving test_complex_oo_syntax----"<<std::endl;
}

void test_complex_functional_syntax(void)
{
    std::cout<<"----Entered test_complex_functional_syntax----"<<std::endl;
    complex c1(1.1,4.5);
    complex c2(3.4,5.6);

    std::plus<complex>complex_addition_operator;
    std::minus<complex>complex_subtraction_operator;

    complex c_sum = complex_addition_operator(c1,c2);
    complex c_sub = complex_subtraction_operator(c1,c2);

    std::cout<<"c1:"<<c1<<std::endl;
    std::cout<<"c2:"<<c2<<std::endl;
    std::cout<<"c_sum:"<<c_sum<<std::endl;
    std::cout<<"c_sub:"<<c_sub<<std::endl;

    std::cout<<"----leaving test_complex_oo_syntax----"<<std::endl;
}

/* 
namespace std
{
    template <typename T> 
    class plus 
    {
        public: 
            T operator()(const T& obj1, const T& obj2)
            {
                return obj1 + obj2; 
            }
    }
}
*/