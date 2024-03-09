#include "company.hpp"

Company::Company(std::string company_name, std::string street_name, std::string street_number, std::string flat_number, std::string postal_code, std::string city, std::string NIP, std::string country) : company_name(company_name), street_name(street_name), street_number(street_number), flat_number(flat_number), postal_code(postal_code), city(city), NIP(NIP), country(country)
{
}

std::string Company::get_company_name() const
{
    return company_name;
}

std::string Company::get_street_name() const
{
    return street_name;
}

std::string Company::get_street_number() const
{
    return street_number;
}

std::string Company::get_flat_number() const
{
    return flat_number;
}

std::string Company::get_postal_code() const
{
    return postal_code;
}

std::string Company::get_city() const
{
    return city;
}

std::string Company::get_NIP() const
{
    return NIP;
}

std::string Company::get_country() const
{
    return country;
}

void Company::set_company_name(std::string company_name)
{
    this->company_name = company_name;
}
void Company::set_street_name(std::string street_name)
{
    this->street_name = street_name;
}

void Company::set_street_number(std::string street_number)
{
    this->street_number = street_number;
}

void Company::set_flat_number(std::string flat_number)
{
    this->flat_number = flat_number;
}

void Company::set_postal_code(std::string postal_code)
{
    this->postal_code = postal_code;
}

void Company::set_city(std::string city)
{
    this->city = city;
}

void Company::set_NIP(std::string NIP)
{
    this->NIP = NIP;
}

void Company::set_country(std::string country)
{
    this->country = country;
}

bool Company::operator==(const Company &other) const
{
    return company_name == other.company_name && street_name == other.street_name && street_number == other.street_number && flat_number == other.flat_number &&
           postal_code == other.postal_code && city == other.city && NIP == other.NIP && country == other.country;
}

bool Company::operator<(const Company &other) const
{
    return company_name < other.company_name;
}

std::ostream &operator<<(std::ostream &os, const Company &Company)
{
    os << Company.company_name << ", " << Company.street_name << " " << Company.street_number << "/" << Company.flat_number << "; " << Company.postal_code << " " << Company.city << "; NIP:" << Company.NIP << "; " << Company.country;
    return os;
}