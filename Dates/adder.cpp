#include "adder.hpp"

eMonth getMonthmFromValue(int value) {
	switch (value) {
	case 1:
		return eMonth::January;
	case 2:
		return eMonth::February;
	case 3:
		return eMonth::March;
	case 4:
		return eMonth::April;
	case 5:
		return eMonth::May;
	case 6:
		return eMonth::June;
	case 7:
		return eMonth::July;
	case 8:
		return eMonth::August;
	case 9:
		return eMonth::September;
	case 10:
		return eMonth::October;
	case 11:
		return eMonth::November;
	case 12:
		return eMonth::December;
	default:
		// Wartość nie pasuje do żadnego enumeratora
		throw std::runtime_error("Nieznana wartość");
	}
}

date::date(int dday, int mmonth, int yyear) //konstruktor argumentowy
	: day(dday), month(mmonth), year(yyear) // lista inicjalizacyjna - przypisanie polom wartości argumentów konstruktora
{
	printDate();
	enumMonth = getMonthmFromValue(month);
}

bool date::dateValidation()
{

	bool iLY = isLapYear();
	if (year < 0)   // nigdy nie wystąpi!
		return false;

	if (month < 1 || month>12)
		return false;

	if (day < 1 || (day > 28 && !iLY && month == 2) || (day > 29 && iLY && month == 2) || (day > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) || (day > 30 && (month == 4 || month == 6 || month == 9 || month == 11))))
		return false;

	return true;
}

bool date::isLapYear() const // lepiej 
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else
		return false;
}

// gettery - pobranie wartości pól
unsigned int date::getDay() const
{
	return day;
}

unsigned int date::getMonth() const
{
	return month;
}

unsigned int date::getYear() const
{
	return year;
}

// settery - modyfikacja pól
void date::setDay(int dday)
{
	day = dday;
	if (!dateValidation())
		std::cout << "Incorrect day in this month! Please set it again.\n";
}
void date::setMonth(int mmonth)
{
	month = mmonth;
	if (!dateValidation())
		std::cout << "Incorrect month! Please set it again.\n";
	enumMonth = getMonthmFromValue(month); // różne typu unsigned int / int
}
void date::setYear(int yyear)
{
	year = yyear;
	if (!dateValidation())
		std::cout << "Incorrect year! Please set it again.\n";
}

// wyświetlenie daty na ekranie
void date::printDate()
{
	if (dateValidation())
		std::cout << "Date: " << day << "." << month << "." << year << '\n';
	else
		std::cout << "Date: " << day << "." << month << "." << year << " is invalid! Please set it again.\n";

}
