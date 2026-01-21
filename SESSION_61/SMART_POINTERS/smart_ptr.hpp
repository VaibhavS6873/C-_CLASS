#ifndef _CPA_SMART_PTR
#define _CPA_SMART_PTR

namespace cpa
{
    template <typename T>
    class smart_ptr
    {
        private:
            T* ptr;

        public:
            smart_ptr(T* _ptr) : ptr(_ptr){}
            ~smart_ptr() {delete ptr; ptr = 0;}
            T* operator->(){return ptr;}
            T& operator*(){return *ptr;}
    };
}

#endif