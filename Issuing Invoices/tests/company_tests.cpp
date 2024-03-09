#include <sstream>
#include "company.hpp"
#include "product.hpp"
#include "invoice.hpp"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("complex number tests", "[complex number]")
{
    Company empty;
    Company basic("Name", "Street", "01", "1A", "01-001", "Citycity", "111-111-11-11", "Country");

    SECTION("tests of constructors, getters and setters")
    {
        CHECK(basic.get_company_name() == "Name");
        CHECK(basic.get_street_name() == "Street");
        CHECK(basic.get_street_number() == "01");
        CHECK(basic.get_flat_number() == "1A");
        CHECK(basic.get_postal_code() == "01-001");
        CHECK(basic.get_city() == "Citycity");
        CHECK(basic.get_NIP() == "111-111-11-11");
        CHECK(basic.get_country() == "Country");

        basic.set_company_name("OtherName");
        CHECK(basic.get_company_name() == "OtherName");
        basic.set_street_name("OtherStreet");
        CHECK(basic.get_street_name() == "OtherStreet");
        basic.set_street_number("20");
        CHECK(basic.get_street_number() == "20");
        basic.set_flat_number("30B");
        CHECK(basic.get_flat_number() == "30B");
        basic.set_postal_code("20-222");
        CHECK(basic.get_postal_code() == "20-222");
        basic.set_city("OtherCity");
        CHECK(basic.get_city() == "OtherCity");
        basic.set_NIP("222-222-22-22");
        CHECK(basic.get_NIP() == "222-222-22-22");
        basic.set_country("OtherCountry");
        CHECK(basic.get_country() == "OtherCountry");
    }
    SECTION("tests of operators")
    {
        Company basic_copy("Name", "Street", "01", "1A", "01-001", "Citycity", "111-111-11-11", "Country");
        Company other("OtherName", "OtherStreet", "20", "30B", "20-222", "OtherCity", "222-222-22-22", "OtherCountry");

        CHECK(basic == basic_copy);
        CHECK_FALSE(basic == other);

        CHECK(basic < other);
        CHECK_FALSE(other < basic);
    }

    SECTION("tests of output operator <<")
    {
        std::stringstream ss;
        ss << basic;
        std::string expected_output = "Name, Street 01/1A; 01-001 Citycity; NIP:111-111-11-11; Country";
        CHECK(ss.str() == expected_output);
    }
}

TEST_CASE("product tests", "[product]")
{
    Product empty_product("", "", 0, 0.0);
    Product laptop("Laptop", "[hardware]", 3, 1200.75);

    SECTION("tests of constructors, getters and setters")
    {
        CHECK(empty_product.get_product_name() == "");
        CHECK(empty_product.get_type() == "");
        CHECK(empty_product.get_count() == 0);
        CHECK(empty_product.get_value() == 0.0);

        CHECK(laptop.get_product_name() == "Laptop");
        CHECK(laptop.get_type() == "[hardware]");
        CHECK(laptop.get_count() == 3);
        CHECK(laptop.get_value() == 1200.75);

        laptop.set_product_name("New Laptop");
        CHECK(laptop.get_product_name() == "New Laptop");
        laptop.set_type("Gadgets");
        CHECK(laptop.get_type() == "Gadgets");
        laptop.set_count(5);
        CHECK(laptop.get_count() == 5);
        laptop.set_value(999.99);
        CHECK(laptop.get_value() == 999.99);
    }

    SECTION("tests of operators")
    {
        Product laptop_copy("Laptop", "[hardware]", 3, 1200.75);
        Product smartphone("Smartphone", "[hardware]", 5, 899.99);

        CHECK(laptop == laptop_copy);
        CHECK_FALSE(laptop == smartphone);

        CHECK(laptop < smartphone);
        CHECK_FALSE(smartphone < laptop);
    }

    SECTION("tests of has_given_name method")
    {
        CHECK(laptop.has_given_name("Laptop"));
        CHECK_FALSE(laptop.has_given_name("Desktop"));
    }

    SECTION("tests of output operator <<")
    {
        std::stringstream ss;
        ss << laptop;
        std::string expected_output = "Laptop [hardware]   Count: 3   Price: 1200.75   Value: 3602.25\n";
        CHECK(ss.str() == expected_output);
    }
}

TEST_CASE("invoice tests", "[invoice]")
{
    Company seller("Seller", "SellerStreet", "01", "1A", "01-001", "SellerCity", "111-111-11-11", "SellerCountry");
    Company buyer("Buyer", "BuyerStreet", "02", "2B", "02-002", "BuyerCity", "222-222-22-22", "BuyerCountry");
    Invoice invoice;

    invoice.set_seller(seller);
    invoice.set_buyer(buyer);

    Product laptop("Laptop", "[hardware]", 3, 1200.75);
    Product smartphone("Smartphone", "[hardware]", 5, 899.99);

    SECTION("tests of product methods")
    {
        invoice.add_product(laptop);
        invoice.add_product(smartphone);

        CHECK(invoice.find_product("Laptop").value() == laptop);
        CHECK_FALSE(invoice.find_product("Desktop").has_value());

        Product new_laptop("Laptop", "[hardware]", 2, 1100.50);
        invoice.edit_product(laptop, new_laptop);
        CHECK(invoice.find_product("Laptop").value() == new_laptop);

        invoice.remove_product(new_laptop);
        CHECK_FALSE(invoice.find_product("Laptop").has_value());
    }
    SECTION("tests of sort methods")
    {
        invoice.add_product(laptop);
        invoice.add_product(smartphone);
        invoice.sort_products_by_product_name();

        auto &products = invoice.get_products();
        CHECK(products[0].get_product_name() <= products[1].get_product_name());

        invoice.sort_products_by_product_type();
        auto &products1 = invoice.get_products();

        CHECK(products1[0].get_type() <= products1[1].get_type());

        invoice.sort_products_by_product_count();
        auto &products2 = invoice.get_products();

        CHECK(products2[0].get_count() <= products2[1].get_count());

        invoice.sort_products_by_product_value();
        auto &products3 = invoice.get_products();

        CHECK(products3[0].get_value() <= products3[1].get_value());
    }

    SECTION("tests of issue_an_invoice s")
    {
        invoice.add_product(laptop);
        invoice.add_product(smartphone);

        std::stringstream output;
        std::streambuf *cout_buffer = std::cout.rdbuf();
        std::cout.rdbuf(output.rdbuf());

        invoice.issue_an_invoice();

        std::cout.rdbuf(cout_buffer);

        std::string expected_output = "============================================================\n"
                                      "INVOICE\n"
                                      "============================================================\n"
                                      "Seller, SellerStreet 01/1A; 01-001 SellerCity; NIP:111-111-11-11; SellerCountry\n\n"
                                      "Bill to:\nBuyer, BuyerStreet 02/2B; 02-002 BuyerCity; NIP:222-222-22-22; BuyerCountry\n"
                                      "-------------------------------------------------------------\n"
                                      "1. Laptop [hardware]   Count: 3   Price: 1200.75   Value: 3602.25\n"
                                      "2. Smartphone [hardware]   Count: 5   Price: 899.99   Value: 4499.95\n"
                                      "-------------------------------------------------------------\n"
                                      "Total value: 8102.20\n"
                                      "=============================================================\n\n\n";

        CHECK(output.str() == expected_output);
    }
}