#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "company.hpp"
#include "product.hpp"

class CompanyFileLoader
{
    std::string file_name;
    std::vector<Company> loader_companies;

public:
    CompanyFileLoader(const std::string &file_name);
    void load_data();
    std::vector<Company> returnCompanies();
};

class ProductFileLoader
{
    std::string file_name;
    std::vector<Product> loader_products;

public:
    ProductFileLoader(const std::string &file_name);
    void load_data();
    std::vector<Product> returnProducts();
};