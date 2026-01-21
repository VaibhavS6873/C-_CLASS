#ifndef _TSF_STACK_EXCEPTIONS_H
#define _TSF_STACK_EXCEPTIONS_H

#include<stdexcept>

class tsf_stack_full : std::runtime_error
{
    public:
        tsf_stack_full(const char* msg) : std::runtime_error(msg)
        {}
};

class tsf_stack_empty : std::runtime_error
{
    public:
        tsf_stack_empty(const char* msg) : std::runtime_error(msg){}
};

#endif