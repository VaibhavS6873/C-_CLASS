#include<iostream>
#include<functional>
#include<cmath>

void testFactory(void);

int main(void)
{
    testFactory();
    return 0;
}

void testFactory(void)
{
    auto powerFunctionFactory = [](int x)->std::function<int(int)>
                                {
                                    return [x](int a)
                                    {
                                        return
                                        static_cast<int>(pow(static_cast<double>(a),static_cast<double>(x)));
                                    };
                                };

    std::function<int(int)>mySquareFunction = powerFunctionFactory(2);
    std::function<int(int)>myCubeFunction = powerFunctionFactory(3);

    int result; 

    result = mySquareFunction(5); 
    std::cout << "Result:" << result << std::endl; // 25 

    result = myCubeFunction(5); 
    std::cout << "Result:" << result << std::endl; // 125 

}