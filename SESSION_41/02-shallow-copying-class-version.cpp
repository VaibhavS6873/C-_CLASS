#include<iostream>
#include <cstdlib>
#include <cassert>

class intPtr
{
    friend class HasPtr;
    private:
         int* p;
        int ref_count;

    intPtr(int data):p(new int(data)),ref_count(1)
    {

    }

    ~intPtr()
    {
        delete p;
        p = 0;
    }
};

class HasPtr
{
    private:
        int n;
       intPtr* pPtr;

    public:
        HasPtr(int _n, int data):n(_n),pPtr(new intPtr(data))
        {
        }

        HasPtr(const HasPtr& other)
        {
            this->n = other.n;
            this->pPtr = other.pPtr;
            this->pPtr->ref_count += 1;
        }

        HasPtr& operator=(const HasPtr& other)
        {
            if(this == &other)
                return *this;

            this->pPtr->ref_count -= 1;
            if(this->pPtr->ref_count == 0)
            {
                std::cout<<"HasPtr::operator=():Ref_count == 0, deleting internal pointers"<<std::endl;
                delete this->pPtr;
            }

            this->pPtr = other.pPtr;
            this->pPtr->ref_count += 1;

            return *this;
        }

        ~HasPtr()
        {
            std::cout<<"HasPtr::~HasPtr():Before decrementing refcount:"
                   <<this->pPtr->ref_count<<std::endl;
            this->pPtr->ref_count -= 1;
            std::cout<<"HasPtr::~HasPtr():After decrementing refcount:"
                   <<this->pPtr->ref_count<<std::endl;

            if(this->pPtr->ref_count == 0)
            {
                std::cout<<"deleting internal pointers"<<std::endl;
                delete this->pPtr;
            }
        }

        int getn()const
        {
            return n;
        }

        void setn(int newN)
        {
            this->n = newN;
        }

         intPtr* getPtr()const
        {
            return this->pPtr;
        }

        int* getP()const
        {
            this->pPtr->p;
        }

        int getVal()const
        {
            return *this->pPtr->p;
        }

        void setVal(int newVal)
        {
            *this->pPtr->p = newVal;
        }

        int getrefCount()const
        {
            return this->pPtr->ref_count;
        }
};

void test_1(void);
void test_2(void);


int main(void)
{
    test_1();
    test_2();
    return 0;
}


void test_1(void)
{
    HasPtr hp1(100, 200);
    HasPtr hp2(200, 300);

    std::cout<<"Adder in pPtr of hp1 and hp2 must be distinct:"<<std::endl;
    std::cout<<"hp1.pPtr:"<<std::hex<<hp1.getPtr()<<std::endl;
    std::cout<<"hp2.pPtr:"<<std::hex<<hp2.getPtr()<<std::endl;

    std::cout<<"printing hp1.pPtr->p and hp2.pPtr->p:"<<std::endl;
    std::cout<<"hp1.pPtr->p:"<<std::hex<<hp1.getP()<<std::endl;
    std::cout<<"hp2.pPtr->p:"<<std::hex<<hp2.getP()<<std::endl;

    std::cout<<"Printing interger pointed by reference counted pointer:"<<std::endl;
    std::cout<<"*hp1.pPtr->p:"<<std::dec<<hp1.getVal()<<std::endl;
    std::cout<<"*hp2.pPtr->p:"<<std::dec<<hp2.getVal()<<std::endl;

    std::cout<<"Printing refernce count of reference counted pointer:"<<std::endl;
    std::cout<<"hp1.pPtr->ref_count:"<<std::dec << hp1.getrefCount()<<std::endl;
    std::cout<<"hp2.pPtr->ref_count:"<<std::dec << hp2.getrefCount()<<std::endl;
}

void test_2(void)
{
    std::cout<<"-----Entered test_2()----"<<std::endl;
    std::cout<<"HasPtr* php1 = new HasPtr(100,200);"<<std::endl;
    HasPtr* php1 = new HasPtr(100,200);
    std::cout<<"php1->getrefCount():"<<php1->getrefCount()<<std::endl;  //1

    std::cout<<"HasPtr* php2 = new HasPtr(*php1);"<<std::endl;
    HasPtr* php2 = new HasPtr(*php1);
    std::cout<<"php1->getrefCount():"<<php1->getrefCount()<<std::endl;  //2
    std::cout<<"php2->getrefCount():"<<php2->getrefCount()<<std::endl;  //2

    std::cout<<"HasPtr* php3 = new HasPtr(*php2);"<<std::endl;
    HasPtr* php3 = new HasPtr(*php2);
    std::cout<<"php1->getrefCount():"<<php1->getrefCount()<<std::endl;  //3
    std::cout<<"php2->getrefCount():"<<php2->getrefCount()<<std::endl;  //3
    std::cout<<"php3->getrefCount():"<<php3->getrefCount()<<std::endl;  //3


    std::cout<<"HasPtr* php4 = new HasPtr(1000,2000);"<<std::endl;
    HasPtr* php4 = new HasPtr(1000,2000);
    std::cout<<"php4->getrefCount():"<<php4->getrefCount()<<std::endl;  //1

    std::cout<<"HasPtr* php5 = new HasPtr(*php4);"<<std::endl;
    HasPtr* php5 = new HasPtr(*php4);
    std::cout<<"php4->getrefCount():"<<php4->getrefCount()<<std::endl;  //2
    std::cout<<"php5->getrefCount():"<<php5->getrefCount()<<std::endl;  //2

    std::cout<<"*php4 = *php3;"<<std::endl;
    *php4 = *php3;
    std::cout << "php1->getrefCount():" << php1->getrefCount() << std::endl; // 4
    std::cout << "php2->getrefCount():" << php2->getrefCount() << std::endl; // 4 
    std::cout << "php3->getrefCount():" << php3->getrefCount() << std::endl; // 4
    std::cout << "php4->getrefCount():" << php4->getrefCount() << std::endl; // 4
    std::cout << "php5->getrefCount():" << php5->getrefCount() << std::endl; // 1

    std::cout<<"*php5 = *php2;"<<std::endl;
    *php5 = *php2;
    std::cout << "php1->getrefCount():" << php1->getrefCount() << std::endl; // 5
    std::cout << "php2->getrefCount():" << php2->getrefCount() << std::endl; // 5 
    std::cout << "php3->getrefCount():" << php3->getrefCount() << std::endl; // 5
    std::cout << "php4->getrefCount():" << php4->getrefCount() << std::endl; // 5
    std::cout << "php5->getrefCount():" << php5->getrefCount() << std::endl; // 5

    std::cout<<"delete php2;"<<std::endl;
    delete php2;
    php2 = 0;
    std::cout << "php1->getrefCount():" << php1->getrefCount() << std::endl; // 4
    std::cout << "php3->getrefCount():" << php3->getrefCount() << std::endl; // 4
    std::cout << "php4->getrefCount():" << php4->getrefCount() << std::endl; // 4
    std::cout << "php5->getrefCount():" << php5->getrefCount() << std::endl; // 4

    std::cout<<"delete php4;"<<std::endl;
    delete php4;
    php4 = 0;
    std::cout << "php1->getrefCount():" << php1->getrefCount() << std::endl; // 3
    std::cout << "php3->getrefCount():" << php3->getrefCount() << std::endl; // 3
    std::cout << "php5->getrefCount():" << php5->getrefCount() << std::endl; // 3

    std::cout<<"delete  php1;"<<std::endl;
    delete php1;
    php1 = 0;
    std::cout<<"php3->getrefCount():" << php3->getrefCount() << std::endl; // 2
    std::cout<<"php5->getrefCount():" << php5->getrefCount() << std::endl; // 2

    std::cout<<"delete php3;"<<std::endl;
    delete php3;
    php3 = 0;
    std::cout<<"php5->getrefCount():" << php5->getrefCount() << std::endl; // 1

    delete php5;
    php5 = 0;

    std::cout<<"REFERENCE COUNT RIGOROUS TESTING OVER"<<std::endl;
    std::cout<<"-----Leaving test_2()-----"<<std::endl;
}
