#ifndef INVOICE_HPP
#define INVOICE_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <optional>
#include <numeric> //std::accumulate
#include <iomanip> //std::fixed, std:setprecision
#include <fstream>
#include "product.hpp"
#include "company.hpp"


class Invoice
{
    std::vector<Product> products;
    std::vector<Product>::iterator find_product(const Product &product);
    std::ofstream outputFile;

    Company seller;
    Company buyer;

public:
    std::optional<Product> find_product(std::string _product_name) const;
    const std::vector<Product> get_products() const;
    void set_seller(const Company& company);
    void set_buyer(const Company& company);
    void add_product(const Product &product);
    bool edit_product(const Product &old_product_data, const Product &new_product_data);
    bool edit_product(std::string old_product_name, const Product &new_product_data);
    void remove_product(const Product &product);
    void remove_product(std::string product_name);
    void sort_products_by_product_name();
    void sort_products_by_product_type();
    void sort_products_by_product_count();
    void sort_products_by_product_value();
    
    void issue_an_invoice();
    void issue_an_invoice_to_file();

    friend std::ostream &operator<<(std::ostream &os, const Invoice &products_list);
};

std::ostream &operator<<(std::ostream &os, const Invoice &products_list);

#endif