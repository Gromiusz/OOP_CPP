#pragma once

#include "figure.hpp"
#include "not_positive_number_exception.hpp"

class Line: public Figure {
private:
    double x2;
    double y2;
    double stroke_width;
public:
    Line(double width, double height, double x, double y, std::string strokeStr, double stroke_width);
    void write_svg(std::ostream& stream) const override;
};

