#ifndef _INSERTION_SORT_HPP
#define _INSERTION_SORT_HPP

#include <iostream>

typedef long long ssize_t;

template<typename T>
void insertionSort(T* arr, ssize_t N)
{
    ssize_t i,j;
    T key;

    for(j = 1; j < N; ++J)
    {
        key = arr[j];
        i = j-1;
        while(i > -1 && arr[i] > key)
        {
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
}

template<typename T>
void show(T* arr, ssize_t N, const char* msg = 0)
{
    if(msg)
        std::cout<<msg<<std::endl;

    for(ssize_t i = 0; i < N; ++i)
        std::cout<<"arr["<<i<<"]"<<arr[i]<<std::endl;
}

#endif
