#include "not_positive_number_exception.hpp"

NotPositiveNumberException::NotPositiveNumberException(double wrong_number):
    std::invalid_argument("Number should be greater than zero: " + std::to_string(wrong_number)), number(wrong_number){}

double NotPositiveNumberException::get_number() const
{
    return number;
}
