#include "calc.hpp"

int sgn (float x)
{
    if(x < 0)
    {
        return -1;
    }
    else if (x == 0)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

float aux_c(float w, float m)
{
    float buff =  sgn(cos(w)) * pow(fabs(cos(w)),m);
    //std::cout << "W - M - Pow aux_c : " << w<<" - "<< m << " - "<< pow(fabs(cos(w)),m) << std::endl;
    //std::cout << "aux_c : " << buff << std::endl;
    return buff;
}

float aux_s(float w, float m)
{
    float buff = sgn(sin(w))*pow(fabs(sin(w)),m);
    return buff;
}

float blend(float x)
{
    return x;
}