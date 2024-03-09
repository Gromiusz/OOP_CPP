#include "figure_list.hpp"

void FigureList::add_figure(std::unique_ptr<Figure> figure)
{
    /*if (const Circle* circle = dynamic_cast<const Circle*>(&figure))
    {
        figures.push_back(std::make_unique<Circle>(*circle));
    }
    else if (const MyRectangle* MyRectangle = dynamic_cast<const MyRectangle*>(&figure))
    {
        figures.push_back(std::make_unique<MyRectangle>(*MyRectangle));
    }*/
    figures.push_back(std::move(figure));

}

const std::list<std::unique_ptr<Figure>>& FigureList::get_figures() const {
    return figures;
}

void FileWriter::write_to_file(const std::string fileName, const std::list<std::unique_ptr<Figure>>& figures) {
    outputFile.open(fileName);
    
    if (!outputFile.is_open()) {
        std::cerr << "Can not open the file: " << fileName << std::endl;
        return;
    }

    outputFile << "<svg version=\"1.1\" width=\"300\" height=\"200\" xmlns=\"http://www.w3.org/2000/svg\">" << std::endl;

    for (const auto& figure : figures) {
        figure->write_svg(outputFile);
    }

    outputFile << "</svg>" << std::endl;
    
    outputFile.close();
}

