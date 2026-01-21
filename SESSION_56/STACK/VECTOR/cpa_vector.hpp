#ifndef _CPA_VECTOR_HPP
#define _CPA_VECTOR_HPP

#include<iostream>

namespace cpa
{
    template <typename T>
    class vector
    {
        private:
            T* pArr;
            std::size_t size;
        public:
            vector() : pArr(0),size(0)
            {

            }

            ~vector()
            {
                if(pArr)
                {
                    delete[] pArr;
                    pArr = 0;
                }
            }

            void push_back(T const& newData)
            {
                pArr = (T*)realloc(pArr, (size +1)*sizeof(T));
                size+=1;
                pArr[size-1] = newData;
            }

            void show(const char* msg = 0)const
            {
                if(msg)
                    std::cout<<msg<<std::endl;

                for(std::size_t i = 0; i < size; ++i)
                {
                    if(msg)
                        std::cout<<msg<<std::endl;

                    for(std::size_t i = 0; i < size; ++i)
                    {
                        std::cout<<"arr["<<i<<"]:"<<pArr[i]<<std::endl;
                    }
                }
            }
    };
}
#endif