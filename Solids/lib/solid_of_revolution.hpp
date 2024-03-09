#pragma once

#include "not_positive_number_exception.hpp"

class SolidOfRevolution{
protected:
    double r;
    double H;

public:
    SolidOfRevolution(double newR, double newH);
    virtual ~SolidOfRevolution();

    void set_r(double newR);
    void set_H(double newH);

    double get_r() const;
    double get_H() const;

    virtual double calculate_base_area() const = 0;
    virtual double calculate_volume() const = 0;

};