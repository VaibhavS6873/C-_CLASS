#include "tsf_stack.hpp"
#include "tsf_stack_exceptions.hpp"
#include <stdexcept>

tsf_stack::tsf_stack(int _size)
{
    if(_size <= 0)
        throw std::domain_error("size cannot be negative");

    size = _size;
    p_stack = new int[size];
    top_index = -1;
}

tsf_stack::~tsf_stack()
{
    delete[] p_stack;
}

void tsf_stack::push(int new_data)
{
    mu_stack.lock();
    if(top_index == size-1)
    {
        mu_stack.unlock();
        throw tsf_stack_full("cannot push in full stack");
    }
    p_stack[++top_index] = new_data;
    mu_stack.unlock();
}

void tsf_stack::top(int* p_top_data)const{
    mu_stack.lock();
    if(top_index == -1)
    {
        mu_stack.unlock();
        throw tsf_stack_empty("cannot pop from empty stack");
    }

    *p_top_data = p_stack[top_index];
    mu_stack.unlock();
}

void tsf_stack::pop(int* p_top_data)    {
    mu_stack.lock();
    if(top_index == -1)
    {
        mu_stack.unlock();
        throw tsf_stack_empty("cannot pop from empty stack");
    }

    *p_top_data = p_stack[top_index--];
    mu_stack.unlock();
}

bool tsf_stack::is_empty()const
{
    mu_stack.lock();
    bool ret = (top_index == -1);
    mu_stack.unlock();
    return ret;
}