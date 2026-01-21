#include<iostream>
#include<cstdlib>

class ArrayOfInts
{
    private:
        int* pInt;
        int N;
    public:
        ArrayOfInts(int _N)
        {
            N = _N;
            if(N <= 0)
            {
                std::cout<<"Array size cannot be negative or zero"<<std::endl;
                exit(-1);
            }

            pInt = new int[N];
        }

        ~ArrayOfInts()
        {
            std::cout<<"-------Entered ArrayOfInts::~ArrayOfInts()-----"<<std::endl;
            delete[] pInt;
            pInt = 0;
        }

        int size()const
        {
            return this->N;
        }

        int& operator[](int index)
        {
            if(index < 0 || index >= N)
            {
                std::cout<<"Index is out of range"<<std::endl;
            }

            return *(pInt + index);
        }
};

void testArrayOfInts(void);

int main(void)
{
    std::cout<<"------[] operator overload-----"<<std::endl;
    testArrayOfInts();
    return 0;
}

void testArrayOfInts(void)
{
    ArrayOfInts A(10);

    for(int i = 0; i!=A.size(); ++i)
    {
        A[i] = (i+1)*100; //ArrayOfInts::operator[](&A,i) = (i+1)*100;
    }

    for(int i = 0; i!=A.size(); ++i)
    {
        int val = A[i]; //int val = ArrayOfInts::operator[](&A,i);
        std::cout<<"Elements at index:"<<i<<":is"<<val<<std::endl;
    }
}

/* 
    int n; 
    int m; 

    n = 10; 

    20 = 10; // lvalue is missing 

    &n = 10; // lvalue missing 

    *(&n) = 10; // *(&n) is an lvalue

    *(pInt + i) = 100; // *(pInt+i) is a valid lvalue

    m = n; 

    movl    n, %eax
    movl    %eax, m
*/