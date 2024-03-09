#ifndef EMPTY_STRING_EXCEPTION_HPP
#define EMPTY_STRING_EXCEPTION_HPP

#include <stdexcept>


class EmptyStringException : public std::invalid_argument
{
    public:
        EmptyStringException();
};

#endif