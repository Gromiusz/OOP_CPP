#include "cvr.hpp" // nazwa


const double milimeters2 = pow(10, -3 * 2);
const double centimeters2 = pow(10, -2 * 2);
const double decimeters2 = pow(10, -1 * 2);
const double meters2 = 1;
const double macaws = pow(10, 1 * 2);
const double acres = 0.4047 * pow(10, 2 * 2);
const double hectares = pow(10, 2 * 2);
const double kilometers2 = pow(10, 3 * 2);


double convertor::convertToMeters(double value, int option)
{
	switch (option)
	{
	case 1:
		return value * milimeters2;
		break; // << nigdy tu nie dojdziemy
	case 2:
		return value * centimeters2;
		break;
	case 3:
		return value * decimeters2;
		break;
	case 4:
		return value * meters2;
		break;
	case 5:
		return value * macaws;
		break;
	case 6:
		return value * acres;
		break;
	case 7:
		return value * hectares;
		break;
	case 8:
		return value * kilometers2;
		break;
	}

	// co jeśli tu dojdziemy? co zwraca return ?
}


void convertor::enter2(double fValue, int pUnit, int dUnit)
{
	firstValue = fValue;
	primalUnit = pUnit;
	desiredUnit = dUnit;

	normalizedValue = convertToMeters(fValue, primalUnit);
	calculatedValue = normalizedValue / convertToMeters(1, desiredUnit);

	std::cout << getFirstValue();
	displayUnit(primalUnit);
	std::cout << "  =  " << getCalculatedValue();
	displayUnit(desiredUnit);
	std::cout << "\n\n";
}

double convertor::getFirstValue() const
{
	return firstValue;
}

double convertor::getCalculatedValue() const
{
	return calculatedValue;
}

void convertor::displayUnit(int optionNumber)
{
	switch (optionNumber)
	{
	case 1:
		std::cout << " mm^2";
		break;
	case 2:
		std::cout << " cm^2";
		break;
	case 3:
		std::cout << " dm^2";
		break;
	case 4:
		std::cout << " m^2";
		break;
	case 5:
		std::cout << " macaws";
		break;
	case 6:
		std::cout << " acres";
		break;
	case 7:
		std::cout << " hectares";
		break;
	case 8:
		std::cout << " km^2";
		break;
	}
}

// niewłaściwa nazwa, unikać operacji wy/wy w klasie (to są rzeczy związane z wykorzystaniem klasy)
void convertor::checkUnitOption(unsigned short int&unit) const
{
	while(unit < 1 || unit>8)
	{ 
		std::cout << "Invalid option! Please choose the right one: ";
		std::cin >> unit;
	}
}

void convertor::enterNumber(double& value, std::string title)
{
	while (true) {
		std::cout << title;
		if (std::cin >> value) {
			// Wczytano liczbę
			break;
		}
		else {
			// Wczytano coś innego niż liczba
			std::cout << "Not a number. Please try again." << std::endl;
			std::cin.clear();  // Resetowanie flagi błędów
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Odrzucenie błędnych danych
		}
	}
}

void convertor::enterNumber(unsigned short int& value, std::string title)
{
	while (true) {
		std::cout << title;
		if (std::cin >> value) {
			// Wczytano poprawną liczbę
			break;
		}
		else {
			// Wczytano coś innego niż liczba
			std::cout << "Not a number. Please try again." << std::endl;
			std::cin.clear();  // Resetowanie flagi błędów
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Odrzucenie błędnych danych
		}
	}
}
