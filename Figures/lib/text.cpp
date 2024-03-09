#include "text.hpp"

Text::Text(double x, double y, double font_size, std::string fillStr, std::string text): font_size(font_size), text(text), Figure(x, y, fillStr, "none")
{
    if(text == "")
    {
        throw EmptyStringException();
    }
}

void Text::write_svg(std::ostream& stream) const
{
    stream << "<text x=\"" << x << "\" y=\"" << y << "\" font-size=\"" << font_size << "\" fill=\"" << fill << "\">" << text << "</text>\n";
}