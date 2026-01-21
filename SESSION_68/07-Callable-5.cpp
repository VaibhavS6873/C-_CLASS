#include<iostream>
#include<functional>

int main(void)
{
    int result = []()-> std::function<int(int,int)>
                    {
                        return [](int x,int y)->int
                        {
                            return x+y;
                        };
                    }()(100,200);

    std::cout<<"Result:"<<result<<std::endl;
    return 0;
}