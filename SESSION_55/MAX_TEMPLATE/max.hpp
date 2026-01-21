#ifndef _MAX_HPP
#define _MAX_HPP

template <typename T> // template parameter list where typename T is template parameter
T const& max(T const& a, T const& b) //const& is used karan mag tyat L-value and R-value donhi taku shkato(T& la fakt L-value chalte) 
// here T const& a and T const& b are template call parameters
{
    if(a > b)
        return a
    return b;
}
#endif 