#include "rectangle.hpp"

MyRectangle::MyRectangle(double width, double height, double x, double y, std::string fillStr, std::string strokeStr): width(width), height(height), Figure(x, y, fillStr, strokeStr)
{
    if(width<=0)
    {
        throw NotPositiveNumberException(width);
    }
    if(height<=0)
    {
        throw NotPositiveNumberException(height);
    }
}

void MyRectangle::write_svg(std::ostream& stream) const
{
    stream << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" fill=\"" << fill << "\" stroke=\"" << stroke << "\" />\n";
}