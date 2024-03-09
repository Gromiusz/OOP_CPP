#pragma once

#include "figure.hpp"
#include "not_positive_number_exception.hpp"


class MyRectangle: public Figure {
private:
    double width;
    double height;
public:
    MyRectangle(double width, double height, double x, double y, std::string fillStr, std::string strokeStr);
    void write_svg(std::ostream& stream) const override;
};

