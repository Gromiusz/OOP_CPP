#include <iostream>
#include "product.hpp"
#include "invoice.hpp"
#include "company.hpp"
#include "file_loader.hpp"

int main()
{
    // dodanie firm
    Company hardware("HardwareSeller", "Kwiatowa", "1", "-", "02-234", "Warszawa", "795-123-53-46", "Polska");
    Company bank("BestBank", "Mnisza", "4", "20", "02-533", "Krakow", "795-654-86-45", "Polska");

    // dodanie produktów oferowanych przez hardwareSeller
    Product cheap_mouse_HS("Cheap computer mouse", "[hardware]", 3, 29.80);
    Product monitor_HS("Medium Monitor", "[hardware]", 2, 198.90);
    Product antivirus("EffectiveAntivirus 1-year", "[program]", 1, 79.99);
    Product hi_end_speakers_HS("Hi-end Speakers", "[hardware]", 1, 1899.89);

    Invoice invoice_HS_BB;
    invoice_HS_BB.set_seller(hardware);
    invoice_HS_BB.set_buyer(bank);

    invoice_HS_BB.add_product(monitor_HS);
    invoice_HS_BB.add_product(cheap_mouse_HS);
    invoice_HS_BB.add_product(antivirus);
    invoice_HS_BB.add_product(hi_end_speakers_HS);

    std::cout << "Initial state of products list:" << std::endl
              << invoice_HS_BB << std::endl;

    // dodanie jeszcze jednego monitora
    monitor_HS.set_count(1);
    invoice_HS_BB.add_product(monitor_HS);

    std::cout << "State of products list:" << std::endl
              << invoice_HS_BB << std::endl;

    // wystawienie faktury
    invoice_HS_BB.issue_an_invoice();

    invoice_HS_BB.sort_products_by_product_value();
    std::cout << "State of sorted products by value:" << std::endl
              << invoice_HS_BB << std::endl;

    invoice_HS_BB.sort_products_by_product_name();

    std::cout << "Sorted invoice by product name:\n";
    invoice_HS_BB.issue_an_invoice();

    // faktura do pliku
    Invoice invoice_file;
    std::ifstream file("input.txt");
    if (file.is_open())
    {
        file.close();

        CompanyFileLoader company_loader("input.txt");
        company_loader.load_data();
        std::vector<Company> loaded_companies = company_loader.returnCompanies();

        ProductFileLoader product_loader("input.txt");
        product_loader.load_data();
        std::vector<Product> loaded_products = product_loader.returnProducts();

        invoice_file.set_seller(loaded_companies[0]);
        invoice_file.set_buyer(loaded_companies[1]);
        for (const auto &product : loaded_products)
        {
            invoice_file.add_product(product);
        }
        invoice_file.sort_products_by_product_type();
        invoice_file.issue_an_invoice();
        invoice_file.issue_an_invoice_to_file();
    }
    else
    {
        std::cerr << "Can not open file" << std::endl;
    }

    return 0;
}