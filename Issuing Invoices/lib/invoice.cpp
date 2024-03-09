#include "Invoice.hpp"
#include <algorithm>

std::vector<Product>::iterator Invoice::find_product(const Product &product)
{
    auto found_product = std::find(products.begin(), products.end(), product);

    return found_product;
}

std::optional<Product> Invoice::find_product(std::string _product_name) const
{

    auto product_it = std::find_if(products.begin(), products.end(),
                                   [&](const Product &p)
                                   { return p.has_given_name(_product_name); });
    if (product_it != products.end())
    {
        return std::optional<Product>(*product_it);
    }
    return std::nullopt;
}

const std::vector<Product> Invoice::get_products() const
{
    return products;
}

void Invoice::set_seller(const Company &company)
{
    seller = company;
}

void Invoice::set_buyer(const Company &company)
{
    buyer = company;
}

void Invoice::add_product(const Product &product)
{
    auto found_product = find_product(product);
    if (found_product == products.end())
    {
        products.push_back(product);
    }
    else
    {
        int new_count = found_product->get_count() + product.get_count();
        found_product->set_count(new_count);
    }
}

bool Invoice::edit_product(const Product &old_product_data, const Product &new_product_data)
{
    if (find_product(new_product_data) == products.end())
    {
        std::replace(products.begin(), products.end(), old_product_data, new_product_data);
        return true;
    }
    return false;
}

bool Invoice::edit_product(std::string old_product_name, const Product &new_product_data)
{
    if (find_product(new_product_data) == products.end())
    {
        std::replace_if(
            products.begin(), products.end(),
            [&](const Product &p)
            { return p.has_given_name(old_product_name); },
            new_product_data);
        return true;
    }
    return false;
}

void Invoice::remove_product(const Product &product)
{

    auto logical_end = std::remove(products.begin(), products.end(), product);

    products.erase(logical_end, products.end());
}

void Invoice::remove_product(std::string product_name)
{
    products.erase(std::remove_if(products.begin(), products.end(),
                                  [&](const Product &p)
                                  { return p.has_given_name(product_name); }),
                   products.end());
}

void Invoice::sort_products_by_product_name()
{
    std::sort(products.begin(), products.end());
}

void Invoice::sort_products_by_product_type()
{
    std::sort(products.begin(), products.end(),
              [](const Product &first, const Product &second)
              { return first.get_type() < second.get_type(); });
}

void Invoice::sort_products_by_product_count()
{
    std::sort(products.begin(), products.end(),
              [](const Product &first, const Product &second)
              { return first.get_count() < second.get_count(); });
}

void Invoice::sort_products_by_product_value()
{
    std::sort(products.begin(), products.end(),
              [](const Product &first, const Product &second)
              { return first.get_value() < second.get_value(); });
}

void Invoice::issue_an_invoice()
{
    double total_value = std::accumulate(products.begin(), products.end(), 0.0,
                                         [](double sum, const Product &product)
                                         { return sum + (product.get_value() * product.get_count()); });
    std::cout << "============================================================\n";
    std::cout << "INVOICE\n";
    std::cout << "============================================================\n";

    std::cout << seller << std::endl
              << std::endl;

    std::cout << "Bill to:" << std::endl;
    std::cout << buyer << std::endl;

    std::cout << "-------------------------------------------------------------\n";
    std::cout << *this;
    std::cout << "-------------------------------------------------------------\n";
    std::cout << "Total value: " << std::fixed << std::setprecision(2) << total_value << std::endl;
    std::cout << "=============================================================\n"
              << std::endl
              << std::endl;
}

void Invoice::issue_an_invoice_to_file()
{
    double total_value = std::accumulate(products.begin(), products.end(), 0.0,
                                         [](double sum, const Product &product)
                                         { return sum + (product.get_value() * product.get_count()); });
    outputFile.open("invoice_output.txt");

    if (!outputFile.is_open())
    {
        std::cerr << "Nie można otworzyć pliku do zapisu." << std::endl;
    }
    outputFile << "============================================================\n";
    outputFile << "INVOICE\n";
    outputFile << "============================================================\n";

    outputFile << seller << std::endl
               << std::endl;

    outputFile << "Bill to:" << std::endl;
    outputFile << buyer << std::endl;

    outputFile << "-------------------------------------------------------------\n";
    outputFile << *this;
    outputFile << "-------------------------------------------------------------\n";
    outputFile << "Total value: " << std::fixed << std::setprecision(2) << total_value << std::endl;
    outputFile << "=============================================================\n"
               << std::endl
               << std::endl;

    outputFile.close();
}

std::ostream &operator<<(std::ostream &os, const Invoice &invoice)
{
    unsigned counter = 1;
    for (const auto &product : invoice.products)
    {
        os << counter << ". " << product;
        counter++;
    }
    return os;
}
