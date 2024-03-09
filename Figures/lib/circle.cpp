#include "circle.hpp"

Circle::Circle(double r, double x, double y, std::string fillStr, std::string strokeStr): r(r), Figure(x, y, fillStr, strokeStr)
{
    if(r<=0)
    {
        throw NotPositiveNumberException(r);
    }
}


void Circle::write_svg(std::ostream& stream) const
{
    stream << "<circle cx=\"" << x << "\" cy=\"" << y << "\" r=\"" << r << "\" fill=\"" << fill << "\" stroke=\"" << stroke << "\" />\n";
}