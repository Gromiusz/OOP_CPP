#include "empty_string_exception.hpp"

EmptyStringException::EmptyStringException():
    std::invalid_argument("String should not be empty") {}