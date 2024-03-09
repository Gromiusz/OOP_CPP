#include "fraction.hpp"
#include <sstream>

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("fraction number tests", "[fraction]") 
{
    fraction zero;
    fraction one(1,1);
    fraction fraction_5_over_6(5, 6);
    fraction fraction_1_over_4(1, 4);

    SECTION("addition operator with assignment tests")
    {
        CHECK((one += fraction_1_over_4) == fraction(5, 4));
        CHECK(one == fraction(5, 4));
        CHECK(fraction_1_over_4 == fraction(1, 4));
    }

    SECTION("math operator tests")
    {
        CHECK(zero + one == fraction(1,1));
        CHECK(fraction_5_over_6 + fraction_1_over_4 == fraction(13,12));
        CHECK(fraction_5_over_6 - fraction_1_over_4 == fraction(7,12));
        CHECK(fraction_5_over_6 * fraction_1_over_4 == fraction(5,24));
        CHECK(fraction(-2,3) * fraction(-7,2) == fraction(7,3));
        CHECK(fraction_5_over_6 / fraction(0, 2) == fraction(5,6));
        CHECK(fraction(7,2) / fraction(-3,2) == fraction(-7,3));
    }

    SECTION("comparison tests")
    {
        fraction another_zero;
        fraction another_one(1,1);
        fraction another_fraction_5_over_6(5, 6);
        fraction another_fraction_1_over_4(1, 4);

        CHECK(another_zero == another_zero);
        CHECK(another_one == another_one);
        CHECK(another_fraction_5_over_6 == another_fraction_5_over_6);
        CHECK(another_fraction_1_over_4 == another_fraction_1_over_4);
        CHECK(zero == another_zero);
        CHECK(one == another_one);
        CHECK(fraction_5_over_6 == another_fraction_5_over_6);
        CHECK(fraction_1_over_4 == another_fraction_1_over_4);
        CHECK_FALSE(zero == another_fraction_5_over_6);
        CHECK_FALSE(another_one == another_fraction_1_over_4);

        CHECK_FALSE(zero != another_zero);
        CHECK_FALSE(one != another_one);
        CHECK_FALSE(fraction_5_over_6 != another_fraction_5_over_6);
        CHECK_FALSE(fraction_1_over_4 != another_fraction_1_over_4);

        CHECK(fraction_5_over_6 > fraction_1_over_4);
        CHECK(fraction_5_over_6 >= fraction_1_over_4);
        CHECK(fraction_5_over_6 >= another_fraction_5_over_6);
        CHECK(zero < one);
        CHECK(one <= another_one);
    }

    SECTION("pre-incrementation tests")
    {
        CHECK(++zero == fraction(1,1));
        CHECK(zero == fraction(1,1));

        CHECK(++fraction_1_over_4 == fraction(5,4));
        CHECK(fraction_1_over_4 == fraction(5,4));
        
    }

    SECTION("tests of operator<<")
    {
        std::stringstream stream_zero;
        stream_zero << zero;
        CHECK(stream_zero.str() == "0 / 1\n");
        
        std::stringstream stream_one;
        stream_one << one;
        CHECK(stream_one.str() == "1 / 1\n");

        std::stringstream stream_fraction_5_over_6;
        stream_fraction_5_over_6 << fraction_5_over_6;
        CHECK(stream_fraction_5_over_6.str() == "5 / 6\n");

        std::stringstream stream_fraction_1_over_4;
        stream_fraction_1_over_4 << fraction_1_over_4;
        CHECK(stream_fraction_1_over_4.str() == "1 / 4\n");
    }

    SECTION("tests of constructors, getters and setters")
    {
        CHECK(fraction(5,0) == fraction(5,1));

        CHECK(zero.get_numerator() == 0);
        CHECK(zero.get_denominator() == 1);

        zero.set_numerator(1);
        CHECK(zero.get_numerator() == 1);
        CHECK(zero.get_denominator() == 1);
        zero.set_denominator(2);
        CHECK(zero.get_numerator() == 1);
        CHECK(zero.get_denominator() == 2);

        one.set_fraction(3,4);
        CHECK(one.get_numerator() == 3);
        CHECK(one.get_denominator() == 4);
    }

    SECTION("copy constructor tests")
    {
        fraction fraction_1_over_4_copy(fraction_1_over_4);
        CHECK(fraction_1_over_4_copy == fraction(1, 4));
        CHECK(fraction_1_over_4 == fraction(1, 4));
    }

    SECTION("move constructor tests")
    {
        fraction moved_fraction(std::move(fraction_5_over_6));
        CHECK(moved_fraction == fraction(5, 6));
        CHECK(fraction_5_over_6 == fraction(0, 1));
        CHECK(moved_fraction != fraction_5_over_6);
    }

    SECTION("copy assignment tests")
    {
        fraction result;
        result = fraction_1_over_4;
        CHECK(result == fraction(1, 4));
        CHECK(fraction_1_over_4 == fraction(1, 4));
        CHECK(result == fraction_1_over_4);
    }

    SECTION("move assignment tests")
    {
        fraction result;
        result = fraction_1_over_4 + one;
        CHECK(result == fraction(5, 4));
        CHECK(fraction_1_over_4 == fraction(1, 4));
        CHECK(one == fraction(1, 1));

        result = std::move(fraction_1_over_4);
        CHECK(result == fraction(1, 4));
        CHECK(fraction_1_over_4 == fraction(0, 1));
        CHECK(result != fraction_1_over_4);
    }


   

}
