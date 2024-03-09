#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <iomanip>

class Product
{
    std::string product_name;
    std::string type;
    int count;
    double value;

public:
    Product(std::string product_name, std::string type, int count, double value);

    
    void set_product_name(std::string new_product_name);
    void set_type(std::string new_type);
    void set_count(int new_count);
    void set_value(double new_value);

    std::string get_product_name() const;
    std::string get_type() const;
    int get_count() const;
    double get_value() const;
    
    bool has_given_name(std::string product_name) const;
    bool operator==(const Product &other) const;
    bool operator<(const Product& other) const;

    friend std::ostream &operator<<(std::ostream &os, const Product &product);
};

std::ostream &operator<<(std::ostream &os, const Product &product);

#endif