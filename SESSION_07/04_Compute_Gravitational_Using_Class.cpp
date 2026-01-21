//header file inclusion 
//BUILT IN VARIABLES: DECLARATION -> HEADER FILES , DEFINITION -> LIBRARY
#include<iostream>
#include<exception>
#include<cmath>

class MassAndDistance
{
  private:
    double m1;
    double m2;
    double r;

  public:
    MassAndDistance(double _m1, double _m2, double _r)
    {
        if(_m1 <= 0.0 || _m2<=0.0 || _r<=0.0)
            throw std::domain_error("Bad values for mass and/or distance");
        this->m1 = _m1;
        this->m2 = _m2;
        this->r = _r;
    } 

    double ComputeGravitational()const
    {
        double G = 6.67 * 10e-11;
        double F;

        F = (G * this->m1 *this->m2)/(this->r * this->r);
        return(F);
    }
};

int main(void)
{
    MassAndDistance earthSun(1.9891e30,5.9722e24,149597871000);
    MassAndDistance jupiterSun(1.9891e30,1.89813e27,760070000000);
    double forceBetweenEarthAndSun;
    double forceBetweemJupiterAndSUn;

    forceBetweenEarthAndSun = earthSun.ComputeGravitational();
    forceBetweemJupiterAndSUn = jupiterSun.ComputeGravitational();

    std::cout<<"Force between earth and sun is = "<<forceBetweenEarthAndSun<<"Newton"<<std::endl;
    std::cout<<"Force between jupiter and sun is = "<<forceBetweemJupiterAndSUn<<"Newton"<<std::endl;

    return 0;
}