#ifndef _STACK_HPP
#define _STACK_HPP

const int SUCCESS = 1;
const int STACK_FULL = 2;
const int STACK_EMPTY = 3;

typedef long long ssize_t;
typedef int status_t;

template <typename T>
class Stack
{
    private:
        T* pArr;
        ssize_t N;
        ssize_t topIndex;

    public:
       Stack(ssize_t size):pArr(new T[size]), N(size), topIndex(-1)
       {

       }

        ~Stack()
        {
            if(pArr)
                delete[] pArr;
            pArr = 0;
        }

        status_t push(T newData)
        {
            if((topIndex + 1) == N)
                 return STACK_FULL;
             topIndex = topIndex + 1;
              pArr[topIndex] = newData;
            return SUCCESS;
        }

        status_t top(T* pTopData)
        {
            if(topIndex == -1)
                return STACK_EMPTY;
            *pTopData = pArr[topIndex];
            return SUCCESS;
        }

        status_t pop(T* pPopData)
        {
            if(topIndex == -1)
                return STACK_EMPTY; 
            *pPopData = pArr[topIndex--]; 
            return SUCCESS;
        }

        bool empty()const
        {
            return (topIndex == -1); 
        }
};

#endif