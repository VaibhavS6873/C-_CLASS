#include<iostream>

typedef enum{DECIMAL = 0, OCTAL = 1, HEXADECIMAL = 2}FORMAT;

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

        //logical operator overload
        bool operator&&(const CPA_int& other)const
        {
            return num && other.num;
        }

        bool operator||(const CPA_int& other)const
        {
            return num || other.num;
        }

      
        bool operator>(const CPA_int &other)const
        {
            bool tmp;
            tmp = this->num > other.num;
            return (tmp);
        }

        bool operator!()const
        {
            return !this->num;
        }

          //comparison operator overload 
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

        //bitwise operator overload
        CPA_int operator&(const CPA_int& other)const
        {
            return CPA_int(this->num & other.num);
        }

         CPA_int operator|(const CPA_int& other)const
        {
            return CPA_int(this->num | other.num);
        }

         CPA_int operator^(const CPA_int& other)const
        {
            return CPA_int(this->num ^ other.num);
        }

        CPA_int operator~()const
        {
            return CPA_int(~num);
        }

        //shift operator overload
        CPA_int operator<<(const CPA_int& other)const
        {
            return CPA_int(this->num << other.num);
        }

         CPA_int operator<<(const int shift_bits)const
        {
            return CPA_int(this->num << shift_bits);
        }

        CPA_int operator>>(const CPA_int& other)const
        {
            return CPA_int(this->num >> other.num);
        }

        CPA_int operator>>(const int shift_bits)const
        {
            return CPA_int(this->num >> shift_bits);
        }
       

        void show(FORMAT format = DECIMAL)const
        {
           switch(format)
           {
            case DECIMAL:
                std::cout<<"Internal value of num:"<<std::dec<<num<<std::endl;
                break;
            case HEXADECIMAL:
                std::cout<<"Internal value of num:"<<std::hex<<num<<std::endl;
                break;
           }

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

    sum = n1 + n2; //n1.operator+(n2) == CPA_int::operator+(&n1,n2)
    sub = n1-n2; //n1.operator-(n2) == CPA_int::operator-(&n1,n2)
    mul = n1*n2; //n1.operator*(n2) == CPA_int::operator*(&n1,n2)
    Q = n1/n2; //n1.operator/(n2) == CPA_int::operator/(&n1,n2)
    R = n1%n2; //n1.operator%(n2) == CPA_int::operator%(&n1,n2)

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

    b = n1 < n2; //n1.operator<(&n2) == CPA_int::operator<(&n1,n2)->bool
    std::cout<<"printing return value of n1 < n2:"<<b<<std::endl; //0

    b = n1 <= n2; //n1.operator<=(&n2) == CPA_int::operator<=(&n1,n2)->bool
    std::cout<<"printing return value of n1 <= n2:"<<b<<std::endl; //0

    b = n1 == n2; //n1.operator==(&n2) == CPA_int::operator==(&n1,n2)->bool
    std::cout<<"printing return value of n1 == n2:"<<b<<std::endl; //0

    b = n1 != n2; //n1.operator!=(&n2) == CPA_int::operator!=(&n1,n2)->bool
    std::cout<<"printing return value of n1 != n2:"<<b<<std::endl; //1


    CPA_int n3(0xf0f0f0f0), n4(0x0f0f0f0f);
    CPA_int bitwise_and = n3 & n4;
    CPA_int bitwise_or = n3 | n4;
    CPA_int bitwise_xor = n3 ^ n4;
    CPA_int bitwise_not = ~n4;

    std::cout<<"BITWISE-AND of n3, n4:"<<std::endl;
    bitwise_and.show(HEXADECIMAL);
    std::cout<<"BITWISE-OR of n3, n4:"<<std::endl;
    bitwise_or.show(HEXADECIMAL);
    std::cout<<"BITWISE-XOR of n3, n4:"<<std::endl;
    bitwise_xor.show(HEXADECIMAL);
    std::cout<<"BITWISE-NOT of n4:"<<std::endl;
    bitwise_not.show(HEXADECIMAL);

    std::cout<<"----------------SHIFT OPERATORS----------------"<<std::endl;
    CPA_int n5(0x0f0f0f0f), n6(4); 
    CPA_int result_1 = n5 << n6; // CPA_int::operator<<(&n5, n6)
    CPA_int result_2 = n5 << 4;  // CPA_int::operator<<(&n5, 4)

    std::cout<<"Result of n5 << n6:"<<std::endl;
    result_1.show(HEXADECIMAL);
    std::cout<<"Result of n5 << 4:"<<std::endl;
    result_2.show(HEXADECIMAL);

    std::cout << "Showing n5 >> n6:" << std::endl; 
    result_1.show(HEXADECIMAL);
    std::cout << "Showing n5 >> 4" << std::endl; 
    result_2.show(HEXADECIMAL);

    CPA_int n7(0), n8(-100);

    std::cout<<"Showing n7:";
    n7.show();

    std::cout<<"Showing n8:";
    n8.show();

    if(n7 && n8)
    {
        std::cout<<"LOGIAL AND-if block"<<std::endl;
    }
    else
    {
        std::cout<<"LOGICAL AND-else block"<<std::endl;
    }

    if(n7 || n8)
    {
        std::cout<<"LOGICAL OR-if block"<<std::endl;
    }
    else
    {
        std::cout<<"LOGICAL OR-else block"<<std::endl;
    }

    if(!n7)
    {
        std::cout<<"LOGICAL NOT-if block"<<std::endl;
    }
    else
    {
        std::cout<<"LOGICAL NOT-else block"<<std::endl;
    }

    if(!n8)
    {
        std::cout<<"LOGICAL NOT-if block"<<std::endl;
    }
    else
    {
        std::cout<<"LOGICAL NOT-else block"<<std::endl;
    }
    return 0;

}

