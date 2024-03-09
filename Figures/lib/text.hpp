#pragma once

#include "figure.hpp"
#include "empty_string_exception.hpp"


class Text: public Figure {
private:
    double font_size;
    std::string text;
public:
    Text(double x, double y, double font_size, std::string fillStr, std::string text);
    void write_svg(std::ostream& stream) const override;
};

