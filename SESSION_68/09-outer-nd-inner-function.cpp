#include<iostream>
#include<functional>

int main(void)
{
    int result = [](int x, int y)->std::function<int(void)>
                {
                    return [x,y](void)->int
                        {
                            return x+y;
                        };
                }(100,200)();

     std::cout<<"Result:"<<result<<std::endl;
     return 0;
}