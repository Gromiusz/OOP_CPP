#pragma once
#include <iostream>
#include <algorithm>

class fraction
{
    int numerator;
    int denominator;

public:
    fraction();
    fraction(int num, int denom);

    int get_numerator() const;
    int get_denominator() const;
    void set_numerator(int numerator);
    void set_denominator(int denominator);
    void set_fraction(int numerator, int denominator);

    void simplyfiTheFraction();

    fraction& operator++();
    fraction operator++(int);
    fraction& operator+=(const fraction& second_argument);
    fraction operator+(const fraction& second_argument) const;
    fraction& operator-=(const fraction& second_argument);
    fraction operator-(const fraction& second_argument) const;
    fraction& operator*=(const fraction& second_argument);
    fraction operator*(const fraction& second_argument);
    fraction& operator/=(const fraction& second_argument);
    fraction operator/(const fraction& second_argument);

    bool operator==(const fraction& second_argument) const;
    bool operator!=(const fraction& second_argument) const;
    bool operator>(const fraction& second_argument) const;
    bool operator>=(const fraction& second_argument) const;
    bool operator<(const fraction& second_argument) const;
    bool operator<=(const fraction& second_argument) const;        

    fraction(const fraction& source);

//Konstruktor przesuwający - tworzy nowy obiekt na bazie źródłowego, zabierając jego zasoby i "unieważniając" oryginał
    fraction(fraction&& source);
//Kopiujący operator przypisania - "kopiuje" do już istniejącego obiektu, oryginał jest niezależny od wyniku przypisania
    fraction& operator=(const fraction& source);
//Przesuwający operator przypisania - "przenosi" do już istniejącego obiektu, zabierając zasoby oryginalnego obiektu i "unieważniając" go
    fraction& operator=(fraction&& source);

//Destruktor - zwalnia zasoby zajęte przez obiekt
    ~fraction();
    friend std::ostream& operator<<(std::ostream& os, const fraction& frac);
};

std::ostream& operator<<(std::ostream& os, const fraction& frac);
