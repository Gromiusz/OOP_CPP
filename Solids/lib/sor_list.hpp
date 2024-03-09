#include <memory>
#include <list>
#include "cone.hpp"
#include "cylinder.hpp"
#include "solid_of_revolution.hpp"


class SORList
{
protected:
    std::list<std::unique_ptr<SolidOfRevolution>> solids;

public:
    void add_solids(std::unique_ptr<SolidOfRevolution> solid);
    const std::list<std::unique_ptr<SolidOfRevolution>>& get_solids() const;

    double calculate_total_volume();

};