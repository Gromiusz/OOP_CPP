#include "solid_of_revolution.hpp"

SolidOfRevolution::SolidOfRevolution(double newR, double newH): r(newR), H(newH) 
{
    if(r<=0)
    {
        throw NotPositiveNumberException(r);
    }
    if(H<=0)
    {
        throw NotPositiveNumberException(H);
    }
}

SolidOfRevolution::~SolidOfRevolution() {}

void SolidOfRevolution::set_r(double newR)
{
    r = newR;
}
void SolidOfRevolution::set_H(double newH)
{
    H = newH;
}
double SolidOfRevolution::get_r() const
{
    return r;
}
double SolidOfRevolution::get_H() const
{
    return H;
}