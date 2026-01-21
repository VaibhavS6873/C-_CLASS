#include<iostream>

using std::cout;
using std::endl;


namespace X
{
    int num; //data variable inside namespace

    void test() //function inside namespace
    {
        cout<<"HELLO WORLD"<<endl;
    }

    class Date //class inside namespace
    {
        private:
            int day, month, year;
        public:
            Date()
            {
                day = 1;
                month = 10;
                year = 1999;
            }
    };

    typedef int xyz_t; //typedef inside namespace

    namespace Y  //namespace inside namespace
    {
        int p;
    }
} // namespace X

class Test
{
    public:
        int num;
        static int snum;

        void test()
        {
            cout<<"inside test"<<endl;
        }

        static void stest()
        {
            cout<<" Inside static test()"<<endl;
        }

        typedef int pqr_t;

        class PQR
        {
            private:
                int p,q,r;
        };
};

int Test::snum = 100;

void namespace_demo(void);
void class_demo(void);


int main(void)
{
    namespace_demo();
    class_demo();
    return 0;
}

void namespace_demo(void)
{
    X::num = 100;
    X::test();
    X::Date myDate;
    X::xyz_t num2;
    X::Y::p = 200;
}

void class_demo(void)
{
    Test::num; //not allowed  //object required
    Test::test(); //not allowed //object required

    Test::snum = 500;
    Test::stest();
    Test::pqr_t my_name = 600;
    Test::PQR myobject;
} 


//X::Y; //ok

//1] if X is namespace then Y can be
    /*1]data variable
      2]function
      3] class name
      4] typedef name
      5] namespace name
      
  2] if X is class then Y can be
    1]static data variable
    2] static member function
    3]  typedef name
    4] nested class
    Y is available as per private or public*/