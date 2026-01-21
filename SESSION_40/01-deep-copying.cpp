#include<iostream>
#include<cassert>

class HasPtr
{
    private:
        int n;
        int* p;

    public:
        // Control flow will come here when a new object 
        // is initialized by two integer values such as 
        // HasPtr hp(100, 200);
        HasPtr(int _n, int data):n(_n),p(new int(data))
        {

        }

        // Control flow will come here when a new object of HasPtr 
        // will be initialized by the existing object 
        // HasPtr hp1(100, 200); 
        // HasPtr hp2(hp1); // -> this will will trigger the following constructor
        HasPtr(const HasPtr& other)
        {
            this->n = other.n;
             // addr in this->p is garbage or 0. 
            this->p = new int(*other.p);
            // above line will ensure the following conditions: 
            // this->p != other.p 
            // AND 
            // *this->p == *other.p 
        }

        // Control flow will come here when an existing object is assigned 
        // by another existing object such as 
        // HasPtr hp1(100, 200); 
        // HasPtr hp2(1000, 2000); 
        // hp2 = hp1; 
        HasPtr& operator=(const HasPtr& other)
        {
            this->n = other.n;
            // In case copy assignment operator, object pointed by this and object referred 
            // by other -> both are constructed objects. 
            // Therefore, this->p contains a valid address as well as other.p contains a valid address  
            *this->p = *other.p;
            // again we will satisfy both conditions 
            // this->p != other.p && *this->p == *other.p 
            return *this;
        }

          // When any object of HasPtr is about to be freed, the following function 
        // will be called 
        ~HasPtr()
        {
            delete p;
            p = 0;
        }

        int getn()const
        {
            return n;
        }

        int* getp()const
        {
            return p;
        }

        int getpVal()const
        {
            return *p;
        }

        void setn(int newN)
        {
            this->n = newN;
        }

        void setpVal(int newVal)
        {
            *this->p = newVal;
        }
};

void test(void);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    HasPtr hp1(100,200); //parameterized constructor
    HasPtr hp2(hp1); //copy constructor

    int* p1 = hp1.getp();
    int* p2 = hp2.getp();

    assert(p1!=p2 && *p1 == *p2);
    std::cout<<"p1 != p2 && *p1 == *p2->FullFilled for Copy Constructor Case"<<std::endl;

    HasPtr hp3(1000,2000);

    hp3 = hp1;

    p1 = hp3.getp();
    p2 = hp1.getp();

    assert(p1!=p2 && *p1 == *p2);
    std::cout<<"p1 != p2 && *p1 == *p2->FullFilled for Copy Constructor Case"<<std::endl;

}