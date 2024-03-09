#include "sor_list.hpp"

void SORList::add_solids(std::unique_ptr<SolidOfRevolution> solid)
{
    solids.push_back(std::move(solid));
}

const std::list<std::unique_ptr<SolidOfRevolution>>& SORList::get_solids() const {
    return solids;
}

double SORList::calculate_total_volume()
{
    double totalVolume = 0;
    for(const auto &solid : solids)
    {
        totalVolume += solid->calculate_volume();
    }
    return totalVolume;
}