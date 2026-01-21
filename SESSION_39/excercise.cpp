class HasPtr
{
    private: 
        int n; 
        int* p; 

    public: 
        HasPtr(int _n, int data) : n(_n), p(new int(data))
        {

        }

        int getn(){
            return n; 
        }

        void setn(int _n)
        {
            n = _n; 
        }

        int getData()
        {
            return *p; 
        }

        void setData(int newData)
        {
            *p = newData; 
        }

        ~HasPtr()
        {
            delete p; 
            p = 0; 
        }
}; 

void test1(void); 

int main(void)
{
    test1(); 
    return 0; 
}

void test1(void)
{
    HasPtr hp1(100, 200); 

    HasPtr hp2(hp1); // OBJECT SHARING 
    HasPtr hp3(300, 400); 

    hp3 = hp2; // MEMORY LEAK 

    HasPtr* p_hp1 = new HasPtr(100, 200); 
    HasPtr* p_hp2 = new HasPtr(*p_hp1); 

    delete p_hp1; 

    p_hp2->setData(300); // SEGMENTATION FAULT; 
}