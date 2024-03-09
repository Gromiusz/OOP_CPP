#include <iostream>
#include "sor_list.hpp"


int main()
{
    try
    {
    Cylinder cyl1(10,20);
    Cone con1(10,20);

    SORList solidList;
    solidList.add_solids(std::make_unique<Cylinder>(cyl1));
    solidList.add_solids(std::make_unique<Cone>(con1));

    double totalVolume = solidList.calculate_total_volume();
    std::cout << "Total volume of solids: " << totalVolume << std::endl;
    }
    catch(const NotPositiveNumberException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
    Cylinder cyl2(-10,20);

    SORList solidList;
    solidList.add_solids(std::make_unique<Cylinder>(cyl2));
    }

    catch(const NotPositiveNumberException &e1)
    {
        std::cerr << e1.what() << std::endl;
    }


    return 0;
}

