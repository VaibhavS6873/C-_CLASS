//Header file inclusion
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//Defination of structure MassAndDistance
struct MassAndDistance
{ 
    //data layout
    double m1;
    double m2;
    double r;
};

double ComputeGravitational(struct MassAndDistance* pData);

int main(void)
{

    struct MassAndDistance earthsun;
    struct MassAndDistance jupitersun;
    double forceBetweenEarthAndSun;
    double forceBetweenJupiterAndSun;

    earthsun.m1 = 1.9891e30;
    earthsun.m2 = 5.9722e24;
    earthsun.r = 149597871000;

    forceBetweenEarthAndSun = ComputeGravitational(&earthsun);
    printf("Gravitation force between earth and sun  = %lf Newton \n", forceBetweenEarthAndSun);

    jupitersun.m1 = 1.9891e30;
    jupitersun.m2 = 1.89813e27;  
    jupitersun.r = 760070000000;

    forceBetweenJupiterAndSun = ComputeGravitational(&jupitersun);
    printf("Gravitation force between jupiter and sun  = %lf Newton \n", forceBetweenJupiterAndSun);

    return 0;

}

double ComputeGravitational(struct MassAndDistance *pData)
{
    double G = 6.67 * 10e-11;
    double F;

    if(pData->m1 <= 0.0 || pData->m2 <= 0.0 || pData->r <= 0.0)
    {
        return(NAN);
    }

    F = (G * pData->m1 * pData->m2)/(pData->r * pData->r);
    return F;
}