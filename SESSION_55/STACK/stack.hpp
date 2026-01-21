#ifndef _STACK_HPP
#define _STACK_HPP

const int SUCCESS = 1;
const int STACK_FULL = 2;
const int STACK_EMPTY = 3;

typedef long long ssize_t;
typedef int status_t;

class Stack
{
    private:
        int* pArr;
        ssize_t N;
        ssize_t topIndex;

    public:
        Stack(ssize_t size);
        ~Stack();
        status_t push(int newData);
        status_t pop(int* pPopData);
        status_t top(int* pTopData);
        bool empty()const;
};

#endif