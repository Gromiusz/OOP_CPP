#include <iostream>
#include <string>
#include <cmath>

#include <cstdlib>  // konwencja
#include "cvr.hpp"

int main()
{
	char option;
	double value;
	unsigned short int unit;
	unsigned short int toUnit;
	convertor c;

	while (true)
	{
		std::cout << "AREA CONVERSION CALCULATOR\n";
		std::cout << "==========================\n\n";
		std::cout << "R. Enter data/Use calculator for conversion\n";
		std::cout << "C. Clear screen\n";
		std::cout << "E. Exit\n";
		std::cout << "--------------------------\n";
		std::cout << "1. Milimeters\n";
		std::cout << "2. Centimeters\n";
		std::cout << "3. Decimeters\n";
		std::cout << "4. Meters\n";
		std::cout << "5. Macaws\n";
		std::cout << "6. Acres\n";
		std::cout << "7. Hectares\n";
		std::cout << "8. Kilometers\n\n\n";


		while (true)
		{
			std::cout << "Please enter option (R or C or E): ";
			std::cin >> option;

			if (option == 'C')
			{
				system("CLS");
				break;
			}
			if (option == 'E')
			{
				exit(0);
			}
			if (option == 'R')
			{
				c.enterNumber(value, "Please enter value of area: ");

				c.enterNumber(unit, "Please enter unit: ");
				c.checkUnitOption(unit);

				c.enterNumber(toUnit, "Please set unit to conversion to: ");
				c.checkUnitOption(toUnit);
				std::cout << '\n';

				c.enter2(value, unit, toUnit);
			}
			else
			{
				std::cout << "Invalid option! Please try again.\n\n";
			}
		}
	}

	
}
