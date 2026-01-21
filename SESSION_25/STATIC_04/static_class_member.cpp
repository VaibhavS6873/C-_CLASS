#include<iostream>

class Test
{
    private:
        int x;
        static int y; //part 1 of static data member of class
};

int Test::y = 100; //part 2 of static data member of class  