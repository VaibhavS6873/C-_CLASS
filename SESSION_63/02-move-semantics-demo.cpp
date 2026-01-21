#include<iostream>
#include<stdexcept>
#include<cassert>

class CPA_Int
{
    private:
        int* ptr;
    public:
        //default constructor
        CPA_Int() : ptr(0){}

        //parameterized constructor
        CPA_Int(int n) : ptr(new int(n)){}

        //dtor
        ~CPA_Int() 
        {
            delete ptr;
            ptr = 0;
        }

        //copy semantic while one object is being
        //constructed by an existing object.
        //Approach: deep copying
        CPA_Int(const CPA_Int& other)
        {
            this->ptr = new int(*other.ptr);
        }

        //Copy semantic while one existing object
        //is being assigned by another existing object
        //Approach : deep copying 
        CPA_Int& operator=(const CPA_Int& other)
        {
            *this->ptr = *other.ptr;
            return *this;
        }

        //move constructor
       CPA_Int(CPA_Int&& other)
       {
            this->ptr = other.ptr; // Data transfer from source to destination 
            other.ptr = 0  ;        // Source is surrendering its ownership of data 
       }

        CPA_Int& operator=(CPA_Int& other)
        {
            if(this->ptr)
                delete this->ptr;
            this->ptr = other.ptr;  // Data transfer from source to destination 
            other.ptr = 0;          // Source is surrendering its ownership of data 
        }
        int* get_ptr()const{
            return ptr;
        }

        friend std::ostream& operator<<(std::ostream& os, const CPA_Int& other);
};

std::ostream& operator<<(std::ostream& os, const CPA_Int& obj)
{
    os << "INTEGER VAL:" << *obj.ptr;
    return os;
}

void test_copy_semantics(void);
void test_data_transfer(void);

int main(void)
{
    std::cout<<"Entered: main()"<<std::endl;
    test_copy_semantics();
    test_data_transfer();
    std::cout<<"Leaving: main()"<<std::endl;
    return 0;
}

void test_copy_semantics(void)
{
    std::cout<<"Entered : test_copy_semantics()"<<std::endl;
    CPA_Int obj1(100);
    CPA_Int obj2(obj1);

    std::cout<<"obj1:"<<obj1<<std::endl;
    std::cout<<"obj2"<<obj2<<std::endl;

    CPA_Int obj3(300);
    std::cout<<"obj3:"<<obj3<<std::endl;

    obj2 = obj3;

    std::cout<<"obj2 and obj3 after obj2 = obj3"<<std::endl;
    std::cout<<"obj2:"<<obj2<<std::endl;
    std::cout<<"obj3:"<<obj3<<std::endl;
    std::cout<<"Leaving : test_copy_semantics()"<<std::endl;
}

void test_data_transfer(void)
{
    std::cout<<"Entered: test_data_transfer()"<<std::endl;
    CPA_Int obj1(100);
    int* p;

    p = obj1.get_ptr();
    assert(p!=0);
    std::cout<<"obj1.ptr is not NULL"<<std::endl;
    std::cout<<"PRINTING OBJ1:"<<obj1<<std::endl;

    std::cout<<"Creating new object obj2 and initilalizing it by moving data in obj1"<<std::endl;
    CPA_Int obj2(std::move(obj1));

     p = obj2.get_ptr();
    assert(p!=0);
    std::cout<<"obj2.ptr is not NULL"<<std::endl;
    std::cout<<"PRINTING OBJ2:"<<obj2<<std::endl;

    p = obj1.get_ptr();
    assert(p == 0);
    std::cout<<"obj1.ptr is NULL"<<std::endl;

    //testing data transfer for assignment
    CPA_Int obj3(300);
    CPA_Int obj4(400);

    p = obj3.get_ptr();
    assert(p!=0);
    std::cout<<"obj3.ptr is not NULL"<<std::endl;
    std::cout<<"PRINTING OBJ3:"<<obj1<<std::endl;

    p = obj4.get_ptr();
    assert(p!=0);
    std::cout<<"obj4.ptr is not NULL"<<std::endl;
    std::cout<<"PRINTING OBJ4:"<<obj1<<std::endl;

    obj3 = std::move(obj4);

    p = obj3.get_ptr();
    assert(p!=0);
    std::cout<<"obj3.ptr is not NULL after obj3.transfer_data_for_assignment(obj4)"<<std::endl;
    std::cout<<"PRINTING obj3 after obj3.transfer_data_for_assignment(obj4):"<<obj3<<std::endl;

    p = obj4.get_ptr(); 
    assert(p == 0); 
    std::cout << "obj4.ptr is NULL after obj3.transfer_data_for_assignment(obj4)" << std::endl; 
    std::cout << "Leaving:test_data_transfer()" << std::endl; 
}

