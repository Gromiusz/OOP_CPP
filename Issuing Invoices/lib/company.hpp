#ifndef COMPANY_HPP
#define COMPANY_HPP
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Company
{
    std::string company_name;
    std::string street_name;
    std::string street_number;
    std::string flat_number;
    std::string postal_code;
    std::string city;
    std::string NIP;
    std::string country;

public:
    Company() = default;
    Company(std::string company_name, std::string street_name, std::string street_number, std::string flat_number, std::string post_code, std::string city, std::string NIP, std::string country);
    
    std::string get_company_name() const;
    std::string get_street_name() const;
    std::string get_street_number() const;
    std::string get_flat_number() const;
    std::string get_postal_code() const;
    std::string get_city() const;
    std::string get_NIP() const;
    std::string get_country() const;

    void set_company_name(std::string name);
    void set_street_name(std::string street_name);
    void set_street_number(std::string street_number);
    void set_flat_number(std::string flat_number);
    void set_postal_code(std::string post_code);
    void set_city(std::string city);
    void set_NIP(std::string NIP);
    void set_country(std::string country);

    bool operator==(const Company &other) const;
    bool operator<(const Company& other) const;

    friend std::ostream &operator<<(std::ostream &os, const Company &company);
};

std::ostream &operator<<(std::ostream &os, const Company &company);

#endif