#include "color_not_found_exception.hpp"

ColorNotFoundException::ColorNotFoundException(std::string wrong_color):
    std::invalid_argument("Color not found: " + wrong_color), color(wrong_color){}

std::string ColorNotFoundException::get_color() const
{
    return color;
}
