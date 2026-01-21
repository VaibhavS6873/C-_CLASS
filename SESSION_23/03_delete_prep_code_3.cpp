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

        void show()
        {
            std::cout<<"double value = "<<this->d<<"and"<< "int value ="<<*this->i_ptr;
        }

        void free_internal_pointer()
        {
            delete this->i_ptr;
            this->i_ptr = 0;
        }
};


int main(void)
{
    A* A_ptr = new A(34.78, 100);
   

    //A_ptr->i_ptr = new int;

    //A_ptr->d = 34.78;
    //*A_ptr->i_ptr  = 100;

    //std::cout<<"double value = "<<A_ptr->d<<"and"<< "int value ="<<*A_ptr->i_ptr;

    A_ptr->show();

    A_ptr->free_internal_pointer();
    //delete A_ptr->i_ptr;
    delete A_ptr;
    A_ptr = NULL;

    return 0;
}