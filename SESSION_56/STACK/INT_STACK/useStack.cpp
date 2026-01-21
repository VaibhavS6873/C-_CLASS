#include<iostream>
#include<cassert>
#include "stack.hpp"

int main(void)
{
    testWithInt();
    testWithFloat();
    return 0;
}

int testWithInt(void)
{
    int topData, popedData;
    status_t status;

    Stack<int>S(8);
    std::cout << "STACK WITH INT TEST BEGIN" << std::endl; 
    assert(S.top(&topData) == STACK_EMPTY);
    assert(S.pop(&popedData) == STACK_EMPTY);
    assert(S.empty() == true);

    for(ssize_t i = 0; i < 8; ++i)
    {
        status = S.push((i+1)*100);
        assert(status == SUCCESS);
    }

    status = S.push(900);
    assert(status == STACK_FULL);

    status = S.top(&topData);
    assert(status == SUCCESS);
    std::cout << "Top Data:"<<topData<<std::endl;

    while(!S.empty())
    {
        status = S.pop(&popedData);
        assert(status == SUCCESS);
        std::cout<<"popedData:"<<popedData<<std::endl;
    }

    assert(S.top(&topData) == STACK_EMPTY);
    assert(S.pop(&popedData) == STACK_EMPTY);
    assert(S.empty() == true);

    std::cout << "STACK RIGOROUS TESTING COMPLETE" << std::endl; 
    return 0;
}

int testWithFloat(void)
{
    float topData, popedData;
    status_t status;

    Stack<float>S(8);
    std::cout << "STACK WITH FLOAT TEST BEGIN" << std::endl; 
    assert(S.top(&topData) == STACK_EMPTY);
    assert(S.pop(&popedData) == STACK_EMPTY);
    assert(S.empty() == true);

    for(ssize_t i = 0; i < 8; ++i)
    {
        status = S.push((i+1)*100/7.0f);
        assert(status == SUCCESS);
    }

    status = S.push(900.56);
    assert(status == STACK_FULL);

    status = S.top(&topData);
    assert(status == SUCCESS);
    std::cout << "Top Data:"<<topData<<std::endl;

    while(!S.empty())
    {
        status = S.pop(&popedData);
        assert(status == SUCCESS);
        std::cout<<"popedData:"<<popedData<<std::endl;
    }

    assert(S.top(&topData) == STACK_EMPTY);
    assert(S.pop(&popedData) == STACK_EMPTY);
    assert(S.empty() == true);

    std::cout << "STACK RIGOROUS TESTING COMPLETE" << std::endl; 
    return 0;
}