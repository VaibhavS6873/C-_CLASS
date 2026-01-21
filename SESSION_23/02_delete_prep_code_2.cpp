#include<iostream>

class A
{
    public:
        double d;
        int* i_ptr;
};


int main(void)
{
    A* A_ptr = new A;
    A_ptr->i_ptr = new int;

    A_ptr->d = 34.78;
    *A_ptr->i_ptr  = 100;

    std::cout<<"double value = "<<A_ptr->d<<"and"<< "int value ="<<*A_ptr->i_ptr;

    delete A_ptr->i_ptr;
    delete A_ptr;

    A_ptr = NULL;

    return 0;
}