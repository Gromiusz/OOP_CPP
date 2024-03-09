#include "cylinder.hpp"

Cylinder::Cylinder(double newR, double newH): SolidOfRevolution(newR, newH) {}

double Cylinder::calculate_base_area() const
{
    return 3.14*r*r;
}
double Cylinder::calculate_volume() const
{
    double V = calculate_base_area()*H;
    return V;
}
void Cylinder::set_r(double newR)
{
    r = newR;
}
void Cylinder::set_H(double newH)
{
    H = newH;
}
double Cylinder::get_r() const
{
    return r;
}
double Cylinder::get_H() const
{
    return H;
}