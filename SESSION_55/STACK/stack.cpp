#include "stack.hpp"

Stack::Stack(ssize_t size):pArr(new int[size]), N(size), topIndex(-1)
{

}

Stack::~Stack()
{
    if(pArr)
    {
        delete[] pArr;
        pArr = 0;
    }
}

status_t Stack::push(int newData)
{
    if((topIndex + 1) == N)
        return STACK_FULL;
    topIndex = topIndex + 1;
    pArr[topIndex] = newData;
    return SUCCESS;
}

status_t Stack::top(int* pTopData)
{
    if(topIndex == -1)
        return STACK_EMPTY;
    *pTopData = pArr[topIndex];
    return SUCCESS;
}

status_t Stack::pop(int* pPopData)
{
    if(topIndex == -1)
        return STACK_EMPTY;
    *pPopData = pArr[topIndex--];
    return SUCCESS;
}

bool Stack::empty()const
{
    return (topIndex == -1);
}