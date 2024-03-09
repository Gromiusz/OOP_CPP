#include "product.hpp"

Product::Product(std::string product_name, std::string type, int count, double value) : product_name(product_name), type(type), count(count)
{
    set_value(value);
}

void Product::set_product_name(std::string new_product_name)
{
    product_name = new_product_name;
}

void Product::set_type(std::string new_type)
{
    type = new_type;
}

void Product::set_count(int new_count)
{
    count = new_count;
}

void Product::set_value(double new_value)
{
    value = std::floor(new_value * 100) / 100;
}

std::string Product::get_product_name() const
{
    return product_name;
}

std::string Product::get_type() const
{
    return type;
}

int Product::get_count() const
{
    return count;
}

double Product::get_value() const
{
    return value;
}

bool Product::operator==(const Product &other) const
{
    return (product_name == other.product_name);
}

bool Product::operator<(const Product &other) const
{
    return product_name < other.product_name;
}

bool Product::has_given_name(std::string product_name) const
{
    return this->product_name == product_name;
}

std::ostream &operator<<(std::ostream &os, const Product &product)
{
    os << product.product_name << " " << product.type << "   Count: " << product.count << "   Price: ";
    os << std::fixed << std::setprecision(2) << product.value;
    double full_value = product.count * product.value;
    os << "   Value: " << full_value << std::endl;
    return os;
}