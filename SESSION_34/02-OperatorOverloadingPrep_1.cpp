#include<iostream>
#include<typeinfo>

class CPA_int
{
    private:
        int num;
    public:
        CPA_int(int _num = 0):num(_num)
        {}

        CPA_int add(const CPA_int& other)
        {
            CPA_int tmp;
            tmp.num = this->num + other.num;
            return tmp;
        }
        void show()const
        {
            std::cout<<"CPA_int::show():Internal num value inside the calling object:"<<std::dec<<this->num<<std::endl;
    
        }
};

int main(void)
{
    CPA_int n1(100); //internal num value will be 100
    CPA_int n2(200); //internal num value will be 200
    CPA_int sum; //internal num value will be 0

    std::cout<<"main():showing internal num values of n1, n2 and sum respectively"<<std::endl;
    n1.show();
    n2.show();
    sum.show();

    //sum = n1+n2; //ROAD_BLOCK : Binary operator + is not defined on objects of type CPA_int and CPA_int


    sum = n1.add(n2); //this will work

    std::cout<<"main():showing internal num values of n1, n2 and sum respectively"<<std::endl
             <<"after sum = n1.add(n2)"<<std::endl;
   
    n1.show();
    n2.show();
    sum.show();
    return 0;
}