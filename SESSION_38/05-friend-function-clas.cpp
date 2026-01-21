#include<iostream>

class MyClass
{
    friend void test_2(void);
    friend class RandomClass;
    
    private:
        int private_member;
    public:
        MyClass() : private_member(100){}

};

class RandomClass
{
    public:
        void member_fun_1()
        {
            MyClass mc_obj_1;
        }

         void member_fun_2()
        {
            MyClass mc_obj_2;
            mc_obj_2.private_member = 1000;
        }
};

void test_1(void);
void test_2(void);

int main(void)
{
    return 0;
}

void test_1(void)
{
    MyClass mc_object_1;
    //mc_object_1.private_member = 500; //Error
}

void test_2(void)
{
    MyClass mc_object_2;
    mc_object_2.private_member = 1000;
}
