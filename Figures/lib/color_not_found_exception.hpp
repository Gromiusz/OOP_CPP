#ifndef COLOR_NOT_FOUND_EXCEPTION_HPP
#define COLOR_NOT_FOUND_EXCEPTION_HPP

#include <stdexcept>


class ColorNotFoundException : public std::invalid_argument
{
    private:
        std::string color;
    public:
        ColorNotFoundException(std::string wrong_color);
        std::string get_color() const;
};

#endif