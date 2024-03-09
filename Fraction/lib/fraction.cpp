#include "fraction.hpp"


fraction::fraction(): numerator(0), denominator(1)
{
    std::cout << *this;
}
fraction::fraction(int num, int denom): numerator(num), denominator(denom)
{
    if(denominator==0)
    {
        std::cout << "Can not divide by zero! Denominator equals one.\n";
        denominator = 1;
        std::cout << *this;
    }
    else
    {
        simplyfiTheFraction();
        std::cout << *this;
    }
}

int fraction::get_numerator() const
{
    return numerator;
}

int fraction::get_denominator() const
{
    return denominator;
}

void fraction::set_numerator(int numerator)
{
    this -> numerator = numerator;
    simplyfiTheFraction();
}

void fraction::set_denominator(int denominator)
{
    if(denominator==0)
    {
        std::cout << "Can not divide by zero!\n";
    }
    else
    {
        this -> denominator = denominator;
        simplyfiTheFraction();
    }
}
void fraction::set_fraction(int numerator, int denominator)
{
     if(denominator==0)
    {
        std::cout << "Can not divide by zero!\n";
    }
    else
    {
        this -> numerator = numerator;
        this -> denominator = denominator;
        simplyfiTheFraction();
    }
}

void fraction::simplyfiTheFraction()
{
    int ggcd = std::__gcd(numerator,denominator);
    numerator /=ggcd;
    denominator /= ggcd;
    if(numerator*denominator<0)
    {
        numerator = -abs(numerator);
        denominator = abs(denominator);
    }
}

fraction& fraction::operator++()
{
    numerator +=denominator;
    return *this;
}

fraction fraction::operator++(int)
{
    fraction kopia = *this;
    numerator +=denominator;
    return kopia;
}

fraction& fraction::operator+=(const fraction& second_argument)
{
    if(denominator == second_argument.denominator)
    {
        numerator += second_argument.numerator;
    }
    else
    {
        int lcm = (denominator * second_argument.denominator)/std::__gcd(denominator, second_argument.denominator);
        numerator = (lcm/denominator)*numerator + (lcm/second_argument.denominator)*second_argument.numerator;
        denominator = lcm;
    }
    return *this;
}

fraction fraction::operator+(const fraction& second_argument) const
{
    fraction sum = *this;
    sum += second_argument;
    return sum;
}

fraction& fraction::operator-=(const fraction& second_argument)
{
    if(denominator == second_argument.denominator)
    {
        numerator -= second_argument.numerator;
    }
    else
    {
        int lcm = (denominator * second_argument.denominator)/std::__gcd(denominator, second_argument.denominator);
        numerator = (lcm/denominator)*numerator - (lcm/second_argument.denominator)*second_argument.numerator;
        denominator = lcm;
    }
    return *this;
}

fraction fraction::operator-(const fraction& second_argument) const
{
    fraction sum = *this;
    sum -= second_argument;
    return sum;
}

fraction& fraction::operator*=(const fraction& second_argument)
{
    numerator *= second_argument.numerator;
    denominator *= second_argument.denominator;
    return *this;
}

fraction fraction::operator*(const fraction& second_argument)
{
    fraction product = *this;
    product *= second_argument;
    return product;
}
fraction& fraction::operator/=(const fraction& second_argument)
{
     if(second_argument.numerator==0)
    {
        std::cout << "Can not divide by zero! Original value has been kept.\n";
        return *this;
    }
    else
    {
        numerator *= second_argument.denominator;
        denominator *= second_argument.numerator;
        if(numerator*denominator<0)
        {
            numerator = -abs(numerator);
            denominator = abs(denominator);
        }
        return *this;
    }
}

fraction fraction::operator/(const fraction& second_argument)
{
    fraction quotient = *this;
    quotient /= second_argument;
    return quotient;
}

bool fraction::operator==(const fraction& second_argument) const
{
    fraction difference =*this-second_argument;
    return (0==difference.numerator);
}

bool fraction::operator!=(const fraction& second_argument) const
{
    return !(*this == second_argument);
}

bool fraction::operator>(const fraction& second_argument) const
{
    fraction result =*this;
    result -= second_argument;
    return (result.numerator>0);
}

bool fraction::operator>=(const fraction& second_argument) const
{
    return *this>second_argument || *this==second_argument;
}

bool fraction::operator<(const fraction& second_argument) const
{
    return !(*this>=second_argument);
}

bool fraction::operator<=(const fraction& second_argument) const
{
    return !(*this>second_argument);
}

fraction::fraction(const fraction& source) : numerator(source.numerator), denominator(source.denominator)
{
    //std::cout << "Copy constructor, this = " << this << ", source = " << &source << std::endl;
}

fraction::fraction(fraction&& source) : numerator(source.numerator), denominator(source.denominator)
{
    //std::cout << "Move constructor, this = " << this << ", source = " << &source << std::endl;
    source.numerator = 0;
    source.denominator = 1;
}

fraction& fraction::operator=(const fraction& source)
{
    //std::cout << "Copy assignment operator, this = " << this << ", source = " << &source << std::endl;
    if(this != &source)
    {
        numerator = source.numerator;
        denominator = source.denominator;
    }
    return *this;
}

fraction& fraction::operator=(fraction&& source)
{
    //std::cout << "Move assignment operator, this = " << this << ", source = " << &source << std::endl;
    if(this != &source)
    {
        numerator = source.numerator;
        denominator = source.denominator;
        source.numerator = 0;
        source.denominator = 1;
    }
    return *this;
}

fraction::~fraction()
{
    //std::cout << "Destructor, this = " << this << std::endl;
}

std::ostream& operator<<(std::ostream& os, const fraction& frac)
{
    os << frac.numerator << " / " << frac.denominator << '\n';
    return os;
}