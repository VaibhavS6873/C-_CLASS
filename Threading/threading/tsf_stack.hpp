#ifndef _TSF_STACK_HPP
#define _TSF_STACK_HPP

#include "thread.hpp"

class tsf_stack
{
    private:
        int* p_stack;
        int size;
        int top_index;

        mutable cpa::mutex mu_stack;

    public:
        tsf_stack(int _size);
        ~tsf_stack();

        void push(int new_data);
        void top(int* p_top_data)const;
        void pop(int* p_pop_data);
        bool is_empty()const;
};

#endif