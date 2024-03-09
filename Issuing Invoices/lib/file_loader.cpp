#include "file_loader.hpp"

CompanyFileLoader::CompanyFileLoader(const std::string &file_name) : file_name(file_name) {}

void CompanyFileLoader::load_data()
{
    std::ifstream file(file_name);

    if (!file.is_open())
    {
        std::cerr << "Can not open file: " << file_name << std::endl;
        return;
    }

    std::string line;
    int line_counter = 0;

    while (std::getline(file, line))
    {
        line_counter++;

        if (line.empty())
        {
            continue;
        }

        // Seller
        if (line_counter == 1)
        {
            std::istringstream ss(line);
            std::string company_name, street_name, street_number, flat_number, postal_code, city, NIP, country;

            ss >> company_name >> street_name >> street_number >> flat_number >> postal_code >> city >> NIP >> country;

            Company _company(company_name, street_name, street_number, flat_number, postal_code, city, NIP, country);
            loader_companies.push_back(_company);
        }
        // Buyer
        else if (line_counter == 2)
        {
            std::istringstream ss(line);
            std::string company_name, street_name, street_number, flat_number, postal_code, city, NIP, country;

            ss >> company_name >> street_name >> street_number >> flat_number >> postal_code >> city >> NIP >> country;

            Company _company(company_name, street_name, street_number, flat_number, postal_code, city, NIP, country);
            loader_companies.push_back(_company);
        }

        else
        {
            break;
        }
    }
    file.close();
}

std::vector<Company> CompanyFileLoader::returnCompanies()
{
    return loader_companies;
}

ProductFileLoader::ProductFileLoader(const std::string &file_name) : file_name(file_name) {}

void ProductFileLoader::load_data()
{
    std::ifstream file(file_name);

    if (!file.is_open())
    {
        std::cerr << "Can not open file: " << file_name << std::endl;
        return;
    }

    std::string line;
    int line_counter = 0;

    while (std::getline(file, line))
    {
        line_counter++;

        if (line.empty())
        {
            continue;
        }

        if (line_counter > 2)
        {
            std::istringstream ss(line);
            std::string product_name;
            std::string type;
            int count;
            double value;

            ss >> product_name >> type >> count >> value;

            Product _product(product_name, type, count, value);
            loader_products.push_back(_product);
        }
    }

    file.close();
}

std::vector<Product> ProductFileLoader::returnProducts()
{
    return loader_products;
}