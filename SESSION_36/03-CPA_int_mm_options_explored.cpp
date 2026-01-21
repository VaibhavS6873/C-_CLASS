#include<iostream>


class CPA_int
{
    private:
        int n;
    public:
        CPA_int(int _n = 0): n(_n)
        {
        }

        CPA_int operator+(const CPA_int& other)const
        {
            CPA_int tmp;
            tmp.n = this->n + other.n;
            return tmp;
        }

        CPA_int* operator-(const CPA_int& other) const
        {
            CPA_int* pTmp = new CPA_int;
            pTmp->n = this->n - other.n;
            return pTmp;
        }
 
        CPA_int& operator*(const CPA_int& other) const
        {
            CPA_int* pTmp = new CPA_int;
            pTmp->n = this->n*other.n;
            return(*pTmp);
        }

        void show(const char* msg = 0)const
        {
            if(msg)
                std::cout<<msg<<std::endl;
                std::cout<<"n:"<<n<<std::endl;
        }
};

int main(void)
{
    CPA_int n1(20);
    CPA_int n2(7);
    CPA_int n3(5);
    CPA_int sum = n1+n2+n3;

    CPA_int* pSub = n1-n2;
    pSub->show("showing subtraction:");
    delete pSub; //disadv #1
    pSub = 0;
    //n1-n2-n3; //disadv 2 : chaining not allowed

    CPA_int& refMul = n1 * n2;
    refMul.show("showing multiplication:");
    delete &refMul; //disadv #1 : OBSCURE SYNTAX

    CPA_int& result = n1 * n2 * n3; //disadv #2:SUBSTL MEMORY LEAK
                                    // n1 * n2 chi return value
                                   //(dynamic object) is leaked
    result.show("showing multiplication of n1 , n2, & n3:");
    delete &result; //disadv #1 : OBSCURE SYNTAX
    return 0;
}

/* 
    Evaluation of n1 + n2 + n3 

    n1 + n2 -> CPA_int::operator+(&n1, n2) 
    At callee's side &n1 will be caputured by this pointer (pointer to const)
    At callee's side n2 will be captured by const reference variable other 

    The function will return tmp object (which is an object of type CPA_int whose 
    internal variable n holds the summation of internal variable n of n1 and n2)

    tmp + n3 
    CPA_int::operator+(&tmp, n3)

    At callee's side &tmp will be caputured by this pointer (pointer to const)
    At callee's side n3 will be captured by const reference variable other 

    The function will return another tmp object (which is an object of type CPA_int whose 
    internal variable n holds the summation of internal variable n of tmp and n3)

    which we will capture in sum;   

    C++ is a horrible language. It is made more horrible by the fact 
    that lot of mediocre programmers use it. - Linus Torvalds 
*/