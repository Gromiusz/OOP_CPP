#ifndef NOT_POSITIVE_NUMBER_EXCEPTION_HPP
#define NOT_POSITIVE_NUMBER_EXCEPTION_HPP

#include <stdexcept>


class NotPositiveNumberException : public std::invalid_argument
{
    private:
        double number;
    public:
        NotPositiveNumberException(double wrong_number);
        double get_number() const;
};

#endif