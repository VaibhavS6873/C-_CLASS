#include<iostream>
#include<cmath>
#include<cstdlib>

class Quadrilateral
{
    private:
        double s1,s2,s3,s4;
    public:
        Quadrilateral(double _s1, double _s2, double _s3, double _s4)
        {
            if(_s1 <= 0.0 || _s2 <= 0.0 || _s3 <= 0.0 || _s4 <= 0.0)
            {
                std::cerr<<"side of quadrilateral cannot be zero or negative"<<std::endl;
                exit(EXIT_FAILURE);
            }


        if(
            _s1 + _s2 + _s3 <= _s4 ||
            _s1 + _s2 + _s4 <= _s3 ||
            _s1 + _s3 + _s4 <= _s2 ||
            _s2 + _s3 + _s4 <= _s1
        )
        {
            std::cerr<<"Sides do not form valid quadilateral"<<std::endl;
            exit(EXIT_FAILURE);
        }

          s1 = _s1;
         s2 = _s2;
         s3 = _s3;
         s4 = _s4;
        }

        double perimeter()const
        {
            return s1 + s2 + s3 + s4;   
        }

        double area()const
        {
            double s = (s1 + s2 + s3 + s4)/2;
            return sqrt((s-s1)*(s-s2)*(s-s3)*(s-s4));
        }
};

void test(void);

int main(void)
{
    test();
    return 0;
}

void test(void)
{
    Quadrilateral Q(6.3, 2.5, 3.5, 4.1);

    double perimeter = Q.perimeter();
    double area = Q.area();

    std::cout<<"Perimeter of quadrilateral is "<<perimeter<<std::endl;
    std::cout<<"Area of quadrilateral is "<<area<<std::endl;
}