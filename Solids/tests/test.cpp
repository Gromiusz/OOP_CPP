#include "sor_list.hpp"
#include <string>


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Test of exceptions", "[exceptions]")
{
    SECTION("NotPositiveNumberException")
    {
        double notPositiveNumber = -3;
        NotPositiveNumberException exception(notPositiveNumber);

        REQUIRE(std::string(exception.what()) == "Number should be greater than zero: " + std::to_string(notPositiveNumber));
        REQUIRE(exception.get_number() == -3);
    }
}

TEST_CASE("Test of cone", "[cone]")
{
    SECTION("test setters and getters")
    {
        Cone cone1(5,4);

        REQUIRE(cone1.get_r() == 5);
        REQUIRE(cone1.get_H() == 4);

        cone1.set_r(1);
        cone1.set_H(2);
        CHECK(cone1.get_r() == 1);
        CHECK(cone1.get_H() == 2);
    }
    SECTION("test setters and getters")
    {
        Cone cone1(5,4);

        REQUIRE(cone1.calculate_base_area() == 78.5);
        CHECK(cone1.calculate_volume() == 314.0/3);
    }
    SECTION("test exceptions")
    {
        CHECK_NOTHROW(Cone(2,3));
        CHECK_THROWS_AS(Cone(0,3),NotPositiveNumberException);
        CHECK_THROWS_AS(Cone(2,-1), NotPositiveNumberException);
    }
}

TEST_CASE("Test of cylinder", "[cylider]")
{
    SECTION("test setters and getters")
    {
        Cylinder cylinder1(5,4);

        REQUIRE(cylinder1.get_r() == 5);
        REQUIRE(cylinder1.get_H() == 4);

        cylinder1.set_r(1);
        cylinder1.set_H(2);
        CHECK(cylinder1.get_r() == 1);
        CHECK(cylinder1.get_H() == 2);
    }
    SECTION("test setters and getters")
    {
        Cylinder cylinder1(5,4);

        REQUIRE(cylinder1.calculate_base_area() == 78.5);
        CHECK(cylinder1.calculate_volume() == 314);
    }
    SECTION("test exceptions")
    {
        CHECK_NOTHROW(Cylinder(2,3));
        CHECK_THROWS_AS(Cylinder(0,3),NotPositiveNumberException);
        CHECK_THROWS_AS(Cylinder(2,-1), NotPositiveNumberException);
    }
}

TEST_CASE("Adding solids to SORList", "[SORList]")
{
    SORList sorList;

    SECTION("Add one solid")
    {
        std::unique_ptr<SolidOfRevolution> cone = std::make_unique<Cone>(1.0, 2.0);
        sorList.add_solids(std::move(cone));

        REQUIRE(sorList.get_solids().size() == 1);
    }

    SECTION("Add multiple solids")
    {
        std::unique_ptr<SolidOfRevolution> cone = std::make_unique<Cone>(1.0, 2.0);
        std::unique_ptr<SolidOfRevolution> cylinder = std::make_unique<Cylinder>(1.0, 2.0);
        
        sorList.add_solids(std::move(cone));
        sorList.add_solids(std::move(cylinder));

        REQUIRE(sorList.get_solids().size() == 2);
    }
}

TEST_CASE("Calculate total volume of SORList", "[SORList]")
{
    SORList sorList;

    SECTION("Calculate total volume for an empty list")
    {
        CHECK(sorList.calculate_total_volume() == 0.0);
    }

    SECTION("Calculate total volume for a list with one solid")
    {
        std::unique_ptr<SolidOfRevolution> cone = std::make_unique<Cone>(1.0, 2.0);
        sorList.add_solids(std::move(cone));

        CHECK(sorList.calculate_total_volume() == Approx(3.14*2/3));
    }

    SECTION("Calculate total volume for a list with multiple solids")
    {
        std::unique_ptr<SolidOfRevolution> cone = std::make_unique<Cone>(1.0, 2.0);
        std::unique_ptr<SolidOfRevolution> cylinder = std::make_unique<Cylinder>(1.0, 2.0);
        
        sorList.add_solids(std::move(cone));
        sorList.add_solids(std::move(cylinder));

        CHECK(sorList.calculate_total_volume() == Approx(3.14*2/3+3.14*2));
    }
}

TEST_CASE("Get solids from SORList", "[SORList]")
{
    SORList sorList;

    SECTION("Get solids from an empty list")
    {
        const auto& solids = sorList.get_solids();
        REQUIRE(solids.empty());
    }

    SECTION("Get solids from a list with one solid")
    {
        std::unique_ptr<SolidOfRevolution> cone = std::make_unique<Cone>(1.0, 2.0);
        sorList.add_solids(std::move(cone));

        const auto& solids = sorList.get_solids();
        REQUIRE(solids.size() == 1);
        CHECK(solids.front()->get_r() == 1.0);
    }

    SECTION("Get solids from a list with multiple solids")
    {
        std::unique_ptr<SolidOfRevolution> cone = std::make_unique<Cone>(1.0, 2.0);
        std::unique_ptr<SolidOfRevolution> cylinder = std::make_unique<Cylinder>(1.0, 2.0);
        
        sorList.add_solids(std::move(cone));
        sorList.add_solids(std::move(cylinder));

        const auto& solids = sorList.get_solids();
        REQUIRE(solids.size() == 2);
        CHECK(solids.back()->get_H() == 2.0);
    }
}

// Sprawdzenie zachowania wskaźników

TEST_CASE("Pointers test", "[Smart Pointers]")
{
    SORList sorList;

    Cone cone_object(1.0, 2.0);
    std::unique_ptr<Cone> cone_pointer = std::make_unique<Cone>(5.0, 6.0);

    SECTION("Check before adding to list")
    {
        CHECK(cone_object.get_r() == 1.0);
        CHECK(cone_pointer->get_r() == 5.0);
    }

    SECTION("Set new radius and check if it can be changed")
    {
        sorList.add_solids(std::make_unique<Cone>(cone_object)); // do listy dodawany jest nowo stworzony wskaźnik
        auto it = std::next(sorList.get_solids().begin(), 0);

        cone_object.set_r(2.0); // dalej można operować na pierwotnym obiekcie
        // poniższe testy wskazują na to że wskaźnik w liście wskazuje na kopię pierwotnego obiektu. Są one teraz niezależne
        CHECK(cone_object.get_r() == 2.0);
        CHECK((*it)->get_r() == 1.0);

        (*it)->set_r(3.0);
        CHECK((*it)->get_r() == 3.0); // ustawienie nowego promienia wpływa tylko na obiekt, do którego wskaźnik znajduje się w liście
        CHECK(cone_object.get_r() == 2.0); // pierwotny został nienaruszony, co potwierdza ich niezależność
    }

    SECTION("Check if move pointer points to nothing")
    {
        sorList.add_solids(std::move(cone_pointer));
        CHECK(cone_pointer == nullptr); // pierwotny wskaźnik nie wskazuje już na nic. Zatem jest to prawidłowe przeniesienie
    }
}