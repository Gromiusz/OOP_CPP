#include "cone.hpp"

Cone::Cone(double newR, double newH): SolidOfRevolution(newR, newH) {}

double Cone::calculate_base_area() const
{
    return 3.14*r*r;
}
double Cone::calculate_volume() const
{
    double V = calculate_base_area()*H/3; // ADDED poprawiono z 1/3*calculate_base_area()*H na calculate_base_area()*H/3
    return V;
}

void Cone::set_r(double newR)
{
    r = newR;
}
void Cone::set_H(double newH)
{
    H = newH;
}
double Cone::get_r() const
{
    return r;
}
double Cone::get_H() const
{
    return H;
}