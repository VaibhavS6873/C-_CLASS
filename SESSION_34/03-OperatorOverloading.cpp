#include<iostream>

class CPA_int
{
    private:
        int num;
    public:
        CPA_int(int _num = 0):num(_num)
        {

        }

        CPA_int operator+(const CPA_int& other)const //to make const CPA_int* this
        {
            // Control flow will come here every time built in operator + is applied 
            // on two objects of CPA_int class 
            // Left side object address will be in this pointer 
            // We must create a const reference varaible to the right side object 
            // of plus operator 
            CPA_int tmp;
            tmp.num = this->num + other.num;
            return (tmp);
        }

        CPA_int operator-(const CPA_int& other)const //to make const CPA_int* this
        {
            CPA_int tmp;
            tmp.num = this->num - other.num;
            return (tmp);
        }

        CPA_int operator*(const CPA_int& other)const //to make const CPA_int* this
        {
            CPA_int tmp;
            tmp.num = this->num * other.num;
            return (tmp);
        }

        CPA_int operator/(const CPA_int& other)const //to make const CPA_int* this
        {
            CPA_int tmp;
            tmp.num = this->num / other.num;
            return (tmp);
        }

        CPA_int operator%(const CPA_int& other)const //to make const CPA_int* this
        {
            CPA_int tmp;
            tmp.num = this->num % other.num;
            return (tmp);
        }

        bool operator>(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num > other.num;
            return (tmp);
        }

        bool operator>=(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num >= other.num;
            return (tmp);
        }

        bool operator<(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num < other.num;
            return (tmp);
        }

        bool operator<=(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num <= other.num;
            return (tmp);
        }

        bool operator==(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num == other.num;
            return (tmp);
        }

        bool operator!=(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num != other.num;
            return (tmp);
        }

        void show()const
        {
            std::cout<<"Internal value of num:"<<num<<std::endl;
        }

};

int main(void)
{
    CPA_int n1(50);
    CPA_int n2(7);
    CPA_int sum, sub, mul,Q,R;

    std::cout<<"----------------ARITHMETIC OPERATORS----------------"<<std::endl;
    std::cout<<"Before Operations:"<<std::endl;

    std::cout<<"n1:";
    n1.show();

    std::cout<<"n2:";
    n2.show();

    std::cout<<"Summation:";
    sum.show();

    std::cout<<"Subtraction:";
    sub.show();

    std::cout<<"Multiplication:";
    mul.show();

    std::cout<<"Quotient:";
    Q.show();

    std::cout<<"remainder:";
    R.show();

    sum = n1 + n2; //n1.operator+(&n2) == CPA_int::operator+(&n1,n2)
    sub = n1-n2; //n1.operator-(&n2) == CPA_int::operator-(&n1,n2)
    mul = n1*n2; //n1.operator*(&n2) == CPA_int::operator*(&n1,n2)
    Q = n1/n2; //n1.operator/(&n2) == CPA_int::operator/(&n1,n2)
    R = n1%n2; //n1.operator%(&n2) == CPA_int::operator%(&n1,n2)

    std::cout<<"After operations:"<<std::endl;

    std::cout<<"n1:";
    n1.show();

    std::cout<<"n2:";
    n2.show();

    std::cout<<"Summation:";
    sum.show();

    std::cout<<"Subtraction:";
    sub.show();

    std::cout<<"Multiplication:";
    mul.show();

    std::cout<<"Quotient:";
    Q.show();

    std::cout<<"remainder:";
    R.show();

    std::cout<<"----------------COMPARISON OPERATORS----------------"<<std::endl;
    std::cout<<"Priniting current values of n1 and n2:"<<std::endl;

    std::cout<<"n1:";
    n1.show();

    std::cout<<"n2:";
    n2.show();

    bool b;
    b = n1 > n2; //n1.operator>(&n2) == CPA_int::operator>(&n1,n2)->bool
    std::cout<<"printing return value of n1 > n2:"<<b<<std::endl; //1

    b = n1 >= n2; //n1.operator>=(&n2) == CPA_int::operator>=(&n1,n2)->bool
    std::cout<<"printing return value of n1 >= n2:"<<b<<std::endl; //1

    b = n1 < n2; //n1.operator<(&n2) == CPA_int::operator<&(&n1,n2)->bool
    std::cout<<"printing return value of n1 < n2:"<<b<<std::endl; //0

    b = n1 <= n2; //n1.operator<=(&n2) == CPA_int::operator<=(&n1,n2)->bool
    std::cout<<"printing return value of n1 <= n2:"<<b<<std::endl; //0

    b = n1 == n2; //n1.operator==(&n2) == CPA_int::operator==(&n1,n2)->bool
    std::cout<<"printing return value of n1 == n2:"<<b<<std::endl; //0

    b = n1 != n2; //n1.operator!=(&n2) == CPA_int::operator!=(&n1,n2)->bool
    std::cout<<"printing return value of n1 != n2:"<<b<<std::endl; //1

    return 0;

}

/* 
    c = a + b; 

    type(a)  == int 
    type(b) == int 
    type(a+b) == int 

    type(c) == int 

    type(lhs) == int 
    type(rhs) == int 

    type checking SUCCESS 

    a: CPA_int 
    b: CPA_int 
    v = a + b 
    
    a + b is evaluated by function call: CPA_int::operator+(&n1, n2); 
    if type checking is to succeed here then 
    type(v) should be the return type annoation of member function 
    CPA_int::operator+

    जड प्रारब्ध : पुरुषार्थ प्रयत्न 
*/