#include "line.hpp"

Line::Line(double x, double y, double x2, double y2, std::string strokeStr, double stroke_width): x2(x2), y2(y2), stroke_width(stroke_width), Figure(x, y, "none", strokeStr)
{
    if(x2<=0)
    {
        throw NotPositiveNumberException(x2);
    }
    if(y2<=0)
    {
        throw NotPositiveNumberException(y2);
    }
    if(stroke_width<=0)
    {
        throw NotPositiveNumberException(stroke_width);
    }
}

void Line::write_svg(std::ostream& stream) const
{
    stream << "<line x1=\"" << x << "\" y1=\"" << y << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" stroke=\"" << stroke << "\" stroke-width=\"" << stroke_width << "\" />\n";
}