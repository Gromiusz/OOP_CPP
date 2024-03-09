#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include "color_not_found_exception.hpp"

enum Color{
    none,
    blue,
    red,
    white,
    black,
    green,
    yellow
};

class Fill{
    Color color;
public:
    Fill(Color color=none);
    Color getColor() const;
    friend std::ostream& operator<<(std::ostream& os, const Fill& fill);

};

class Stroke{
    Color color;
public:
    Stroke(Color color=none);
    Color getColor() const;
    friend std::ostream& operator<<(std::ostream& os, const Stroke& stroke);
};

class Figure{
protected:
    double x;
    double y;

    Stroke stroke;
    Fill fill;

public:
    Figure(double x, double y, std::string fillStr, std::string strokeStr);
    
    virtual void write_svg(std::ostream& stream) const = 0;
    virtual ~Figure();
    Color stringToColor(const std::string& colorStr);

};

std::ostream& operator<<(std::ostream& os, const Fill& fill);
std::ostream& operator<<(std::ostream& os, const Stroke& stroke);