#include<iostream>
#include<cstring>


class A
{
    private:
        double d;
        int* i_ptr;

    public:
        A(double _d, int _n)
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
            std::cout<<"Double val:"<<this->d<<","<<"int val:"<<*this->i_ptr<<std::endl;
        }
};

class B
{
    private:
        float f_arr[4]; //16 byte;
        A* A_ptr; //8 byte;
        int i_arr[4]; //16 byte;

    public: 
        B()
        {
            memset((void*)f_arr, 0, 4 * sizeof(float));
            memset((void*)i_arr, 0 , 4 * sizeof(int));
            A_ptr = new A(45.78, 100);
        }

        void show()
        {
            std::cout<<"showing f_arr"<<std::endl;
            for(int i = 0; i<4; ++i)
            {
                std::cout<<"f_arr["<<i<<"]:"<<this->f_arr[i]<<std::endl;

            }

            std::cout<<"showinf i_arr"<<std::endl;
            for(int i = 0; i<4; i++)
            {
                std::cout<<"i_arr["<<i<<"]:"<<this->i_arr[i]<<std::endl;
            }

            std::cout<<"showing A_ptr:"<<std::endl;
            this->A_ptr->show();
        }

        ~B()
        {
            delete this->A_ptr; //trigger a call to A::~A()
            this->A_ptr = 0;
        }
};

int main(void)
{
    B* pB = new B;

    pB->show();
    delete pB;

    pB = 0;
    return 0;
}