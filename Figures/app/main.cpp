#include "figure_list.hpp"



int main() {
    
    try
    {
        MyRectangle rec1(30, 40, 100, 50, "blue", "none");
        MyRectangle rec2(60, 80, 200, 50, "green", "red");
        Line line1(2,4,20,30, "yellow", 4);
        Circle circle(10, 80,50, "green", "none");

        std::string str1 = "Hello!";
        Text text1(20,20,16, "black", str1);

        FigureList figures;
        figures.add_figure(std::make_unique<MyRectangle>(rec1));
        figures.add_figure(std::make_unique<MyRectangle>(rec2));
        figures.add_figure(std::make_unique<Line>(line1));
        figures.add_figure(std::make_unique<Text>(text1));
        figures.add_figure(std::make_unique<Circle>(circle));

        // Dodaj obiekty do listy figures

        FileWriter Writer;
        Writer.write_to_file("output.svg", figures.get_figures());
    }
    catch(const NotPositiveNumberException& e)
    {
        std::cerr << "Exception NotPositiveNumberException has been catched ---- " << e.what() << std::endl;
    }
    catch(const EmptyStringException& e1)
    {
        std::cerr << "Exception EmptyStringException has been catched ---- " << e1.what() << std::endl;
    }
    catch(const ColorNotFoundException &e11)
    {
        std::cerr << "Exception ColorNotFoundException has been catched ---- " << e11.what() << std::endl;
    }


    try
    {
        Circle circle2(-2, 80,50, "green", "none");

        FigureList figures2;
        figures2.add_figure(std::make_unique<Circle>(circle2));

        FileWriter Writer2;
        Writer2.write_to_file("output2.svg", figures2.get_figures());
    }
    catch(const NotPositiveNumberException& e2)
    {
        std::cerr << "Exception NotPositiveNumberException has been catched ---- " << e2.what() << std::endl;
    }

    try
    {
        std::string str3 = "";
        Text text3(20,20,16, "black", str3);

        FigureList figures3;
        figures3.add_figure(std::make_unique<Text>(text3));

        FileWriter Writer3;
        Writer3.write_to_file("output3.svg", figures3.get_figures());
    }
    catch(const EmptyStringException& e3)
    {
        std::cerr << "Exception EmptyStringException has been catched ---- " << e3.what() << std::endl;
    }

    try
    {
        MyRectangle rec4(30, 40, 100, 50, "purple", "none");

        FigureList figures4;
        figures4.add_figure(std::make_unique<MyRectangle>(rec4));

        FileWriter Writer4;
        Writer4.write_to_file("output4.svg", figures4.get_figures());
    }
    catch(const ColorNotFoundException& e4)
    {
        std::cerr << "Exception ColorNotFoundException has been catched ---- " << e4.what() << std::endl;
    }


    return 0;
}