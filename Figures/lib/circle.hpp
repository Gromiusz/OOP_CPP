#pragma once

#include "figure.hpp"
#include "not_positive_number_exception.hpp"

class Circle: public Figure {
    double r;

public:
    Circle(double r, double x, double y, std::string fillStr, std::string strokeStr);
    void write_svg(std::ostream& stream) const override;
};