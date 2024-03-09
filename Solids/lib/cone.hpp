#pragma once

#include "solid_of_revolution.hpp"

class Cone: public SolidOfRevolution{
public:
    Cone(double newR, double newH);

    void set_r(double newR);
    void set_H(double newH);

    double get_r() const;
    double get_H() const;

    double calculate_base_area() const override;
    double calculate_volume() const override;
};