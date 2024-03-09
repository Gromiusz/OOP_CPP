#pragma once
#include <iostream>

enum class eMonth
{
	January = 1,
	February = 2,
	March = 3,
	April = 4,
	May = 5,
	June = 6,
	July = 7,
	August = 8,
	September = 9,
	October = 10,
	November = 11,
	December = 12
};

class date
{
	unsigned int day;
	unsigned int month; // powieleni month / enumMonth czy potrzebne?
	eMonth enumMonth;
	unsigned int year;

	bool dateValidation();
	bool isLapYear() const;  

public:
	date(int dday, int mmonth, int yyear); //konstruktor argumentowy

	// gettery - pobranie wartości pól
	unsigned int getDay() const;
	unsigned int getMonth() const;
	unsigned int getYear() const;

	// settery - modyfikacja pól
	void setDay(int dday);
	void setMonth(int mmonth);
	void setYear(int yyear);

	// wyświetlenie daty na ekranie
	void printDate();
};
