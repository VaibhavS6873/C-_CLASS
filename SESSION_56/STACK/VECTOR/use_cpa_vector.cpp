#include "cpa_vector.hpp"

int main(void)
{
    cpa::vector<int>iVec;
    cpa::vector<float>fVec;

    for(std::size_t i = 0 ; i < 8; ++i)
    {
        iVec.push_back((i+1)*100);
        fVec.push_back(((i+1)*100)/7.0f);
    }

    iVec.show("Integer array:");
    fVec.show("Float array:");
    return 0;
}