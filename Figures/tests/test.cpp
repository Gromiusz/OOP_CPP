#include "figure.hpp"
#include "figure_list.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Fill", "[fill]") {
    SECTION("Default constructor") {
        Fill fill;
        CHECK(fill.getColor() == none);
    }

    SECTION("Custom constructor") {
        Fill fill(blue);
        CHECK(fill.getColor() == blue);
    }

    SECTION("Output stream operator") {
        Fill fill(green);
        std::ostringstream oss;
        oss << fill;
        CHECK(oss.str() == "green");
    }
}

TEST_CASE("Stroke", "[stroke]") {
    SECTION("Default constructor") {
        Stroke stroke;
        CHECK(stroke.getColor() == none);
    }

    SECTION("Custom constructor") {
        Stroke stroke(red);
        CHECK(stroke.getColor() == red);
    }

    SECTION("Output stream operator") {
        Stroke stroke(black);
        std::ostringstream oss;
        oss << stroke;
        CHECK(oss.str() == "black");
    }
}

TEST_CASE("Exceptions", "[exceptions]")
{
    const std::string wrong_color = "purple";

    SECTION("ColorNotFoundException Constructor and Get Color")
    {
        ColorNotFoundException exception(wrong_color);
        CHECK(exception.get_color() == wrong_color);
        CHECK(exception.what() == "Color not found: " + wrong_color);
    }
    SECTION("EmptyStringException Constructor")
    {
        EmptyStringException exception;
        CHECK(std::string(exception.what()) == "String should not be empty");
    }
    SECTION("NotPositiveNumberException Constructor")
    {
        double invalidNumber = -5.0;
        NotPositiveNumberException exception(invalidNumber);

        CHECK(std::string(exception.what()) == "Number should be greater than zero: " + std::to_string(invalidNumber));
        CHECK(exception.get_number() == invalidNumber);
    }
}

TEST_CASE("Text SVG Output", "[text]") {
    SECTION("Valid output") {
        std::ostringstream stream;
        Text text(20.0, 30.0, 12.0, "blue", "Hello, World!");
        text.write_svg(stream);

        std::string expected = "<text x=\"20\" y=\"30\" font-size=\"12\" fill=\"blue\">Hello, World!</text>\n";
        REQUIRE(stream.str() == expected);
    }
}

TEST_CASE("Text Constructor", "[text]") {
    SECTION("Valid input") {
        REQUIRE_NOTHROW(Text(20.0, 30.0, 12.0, "blue", "Hello, World!"));
    }
}

TEST_CASE("MyRectangle Constructor", "[myRectangle]") {
    SECTION("Valid input") {
        REQUIRE_NOTHROW(MyRectangle(30.0, 40.0, 100.0, 50.0, "blue", "red"));
    }

    SECTION("Invalid width - NotPositiveNumberException") {
        REQUIRE_THROWS_AS(MyRectangle(-5.0, 40.0, 100.0, 50.0, "blue", "red"), NotPositiveNumberException);
    }

    SECTION("Invalid height - NotPositiveNumberException") {
        REQUIRE_THROWS_AS(MyRectangle(30.0, -5.0, 100.0, 50.0, "blue", "red"), NotPositiveNumberException);
    }
}

TEST_CASE("MyRectangle SVG Output", "[myRectangle]") {
    SECTION("Valid input") {
        MyRectangle myRectangle(30.0, 40.0, 100.0, 50.0, "blue", "red");

        std::ostringstream stream;
        myRectangle.write_svg(stream);

        std::string expected = "<rect x=\"100\" y=\"50\" width=\"30\" height=\"40\" fill=\"blue\" stroke=\"red\" />\n";
        REQUIRE(stream.str() == expected);
    }
}


TEST_CASE("Line Constructor", "[line]") {
    SECTION("Valid input") {
        REQUIRE_NOTHROW(Line(10.0, 20.0, 30.0, 40.0, "blue", 2.0));
    }

    SECTION("Invalid x2 - NotPositiveNumberException") {
        REQUIRE_THROWS_AS(Line(10.0, 20.0, -5.0, 40.0, "blue", 2.0), NotPositiveNumberException);
    }

    SECTION("Invalid y2 - NotPositiveNumberException") {
        REQUIRE_THROWS_AS(Line(10.0, 20.0, 30.0, -5.0, "blue", 2.0), NotPositiveNumberException);
    }

    SECTION("Invalid stroke_width - NotPositiveNumberException") {
        REQUIRE_THROWS_AS(Line(10.0, 20.0, 30.0, 40.0, "blue", -2.0), NotPositiveNumberException);
    }
}

TEST_CASE("Line SVG Output", "[line]") {
    SECTION("Valid input") {
        Line line(10.0, 20.0, 30.0, 40.0, "blue", 2.0);

        std::ostringstream stream;
        line.write_svg(stream);

        REQUIRE(stream.str().find("<line x1=\"10\" y1=\"20\" x2=\"30\" y2=\"40\" stroke=\"blue\" stroke-width=\"2\" />\n") != std::string::npos);
    }
}

TEST_CASE("Circle Constructor", "[circle]") {
    SECTION("Valid input") {
        REQUIRE_NOTHROW(Circle(5.0, 10.0, 20.0, "blue", "red"));
    }

    SECTION("Invalid radius - NotPositiveNumberException") {
        REQUIRE_THROWS_AS(Circle(-5.0, 10.0, 20.0, "blue", "red"), NotPositiveNumberException);
    }
}

TEST_CASE("Circle SVG Output", "[circle]") {
    SECTION("Valid input") {
        Circle circle(5.0, 10.0, 20.0, "blue", "red");

        std::ostringstream stream;
        circle.write_svg(stream);

        REQUIRE(stream.str().find("<circle cx=\"10\" cy=\"20\" r=\"5\" fill=\"blue\" stroke=\"red\" />\n") != std::string::npos);
    }
}