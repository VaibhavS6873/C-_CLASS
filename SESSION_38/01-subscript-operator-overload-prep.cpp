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
            std::cout<<"-----Entered ArrayOfInts::~ArrayOfInts()-----"<<std::endl;
            delete[] pInt;
            pInt = 0;
        }

        int size()const
        {
            return this->N;
        }

        void set(int index, int val)
        {
            if(index < 0 || index >=N)
            {
                std::cout<<"ArrayOfInts::set():Index is out of range"<<std::endl;
                exit(-1);
            }
            pInt[index] = val;
        }

        int get(int index)const
        {
            if(index < 0 || index >= N)
            {
                std::cout<<"ArrayOfInts::get():Index is out of range"<<std::endl;
                exit(-1);
            }
            return pInt[index];
        }
        
};

void testArrayOfInts(void);

int main(void)
{
    testArrayOfInts();
    return 0;
}

void testArrayOfInts(void)
{
    ArrayOfInts A(10);

    for(int i = 0; i != A.size(); ++i)
    {
        A.set(i,(i+1)*100); //A[i] = (i+1)*100;
    }

    for(int i = 0; i != A.size(); ++i)
    {
        int val = A.get(i);
        std::cout<<"Element at index:"<<i<<":is"<<A.get(i)<<std::endl;
    }
}

/*
void test(void)
{
    int *pInt = 0;
    int N = 10;

    pInt = new int[N];
    //T* ptrT = new T[sizeofArray];

    delete[] pInt;
    pInt = 0;
}
*/

