#include<iostream>

class A
{
    private:
        double d;
        int* i_ptr;

    public:
        A(double _d , int _n)
        {
            this->d = _d;
            this->i_ptr = new int;
            *this->i_ptr = _n;
        }

        ~A()
        {
            delete this->i_ptr;
            this->i_ptr = 0;
        }
        void show()
        {
            std::cout<<"double value = "<<this->d<<"and"<< "int value ="<<*this->i_ptr;
        }
};


int main(void)
{
    A* A_ptr = new A(34.78, 100);
    A_ptr->show();
    delete A_ptr;  // First call : A::~(A_ptr) and then dynamically allocated object of A 
                  // will be freed
    A_ptr = NULL;

    return 0;
}

// Syntax of destructor 
// 1: Like constructor, destructor is also a public member function 
// 2: Like constructor, destructor also does not have return type annotation 
// 3: Like construtor, the name of destructor is also dependent on class name 
// for constructor, constructor name == class_name 
// for destructor, destuctor name == ~class_name
// 4: One difference between the constructor and the destructor 
// constructor can have more formal parameters than implicit this pointer parameter 
// destructor can have only this pointer as its formal parameter 