#include "figure.hpp"
#include "not_positive_number_exception.hpp"

Fill::Fill(Color color): color(color)
{

}

Stroke::Stroke(Color color): color(color)
{
   
}

Color Fill::getColor() const
{
    return color;
}

Color Stroke::getColor() const
{
    return color;
}

Figure::Figure(double x, double y, std::string fillStr, std::string strokeStr): x(x), y(y)
{
    if(x<=0)
    {
        throw NotPositiveNumberException(x);
    }
    if(y<=0)
    {
        throw NotPositiveNumberException(y);
    }
    this->fill = stringToColor(fillStr);
    this->stroke = stringToColor(strokeStr);
}

Figure::~Figure()
{

}

Color Figure::stringToColor(const std::string& colorStr) {
    static const std::unordered_map<std::string, Color> colorMap = {
        {"none", none},
        {"blue", blue},
        {"red", red},
        {"white", white},
        {"black", black},
        {"green", green},
        {"yellow", yellow}
    };

    auto it = colorMap.find(colorStr);
    if (it != colorMap.end()) {
        return it->second;
    }

    throw ColorNotFoundException(colorStr);
}


std::ostream& operator<<(std::ostream& os, const Fill& fill)
{
    switch (fill.color){
        case none:   os << "none";   break;
        case blue:   os << "blue";   break;
        case red:   os << "red";   break;
        case white:   os << "white";   break;
        case black:   os << "black";   break;
        case green:   os << "green";   break;
        case yellow:   os << "yellow";   break;
    }
    return os;
}

std::ostream& operator<<(std::ostream& os, const Stroke& stroke)
{
    switch (stroke.color){
        case none:   os << "none";   break;
        case blue:   os << "blue";   break;
        case red:   os << "red";   break;
        case white:   os << "white";   break;
        case black:   os << "black";   break;
        case green:   os << "green";   break;
        case yellow:   os << "yellow";   break;
    }
    return os;
}