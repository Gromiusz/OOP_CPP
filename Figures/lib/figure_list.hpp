#include <iostream>
#include <fstream>
#include <list>
#include <memory>
#include "figure.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include "text.hpp"


class FigureList
{
protected:
    std::list<std::unique_ptr<Figure>> figures;

public:
    void add_figure(std::unique_ptr<Figure> figure);
    const std::list<std::unique_ptr<Figure>>& get_figures() const;


};

class FileWriter: protected FigureList {
    std::string fileName;
    std::ofstream outputFile;

public:
    void write_to_file(const std::string fileName, const std::list<std::unique_ptr<Figure>>& figures);
};