#include<iostream>

class X
{
    public:
    int a;
        void f1()
        {
            std::cout<<"in f1()"<<std::endl;
        }

        static void f2()
        {
            std::cout<<"in f2()"<<std::endl;
        }

        static int num;
};

int X::num = 100;

int main(void)
{
    X objX;

    objX.f1(); //ok
    //X::f1(&objX) not allowed

    objX.f2(); // it is allowed but address of objX2 will not be 
              // shared with f2() as a parameter as f2() is a static 
             // member function not having this pointer 
    X::f2(); // static function can be accessed using class name 
            // qualification 
           // even public static data can be accessed likewise 
    X::num = 5000; //ok
    objX.num  = 6000; //ok
   // X::a = 10 //Not ok as it is non-static
}