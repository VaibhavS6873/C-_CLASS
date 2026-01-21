#include<iostream>
#include<functional>

int main(void)
{
    int result = []()->std::function<int(void)>
                {
                    int x=100, y=100;
                    return [x,y](void)->int
                        {
                            return x+y;
                        };
                }()();

    std::cout<<"Result:"<<result<<std::endl;

    return 0;
}