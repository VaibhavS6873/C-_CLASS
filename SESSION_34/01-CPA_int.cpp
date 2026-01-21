#include<iostream>
#include<typeinfo>

class CPA_int
{
    private:
        int num;
    public:
        CPA_int(int _num = 0):num(_num)
        {}

        int get() const
        {
            return this->num;
        }

        void set(int newVal)
        {
            num = newVal;
        }

        void show()const
        {
            std::cout<<"----Entered CPA_int::show()----"<<std::endl
                   <<"CPA_int::show():Address of calling object"<<std::hex<<this<<std::endl;
            std::cout<<"CPA_int::show():Type of calling object:"<<typeid(*this).name()<<std::endl;
            std::cout<<"CPA_int::show():Internal num value inside the calling object:"<<std::dec<<this->num<<std::endl;
            std::cout<<"----Leaving CPA_int::show()----"<<std::endl;
        }
};

int main(void)
{
    CPA_int n1; //internal num value will be 0
    CPA_int n2(200); //internal num value will be 200

    n1.show();
    n2.show();

    n1.set(5000);
    std::cout<<"main():Internal value of n1:"<<n1.get()<<std::endl;

    std::cout<<"main():type(n1)"<<typeid(n1).name()<<std::endl;
    std::cout<<"main():type(n2)"<<typeid(n2).name()<<std::endl;
    return 0;
}