#ifndef CVR_HPP
#define CVR_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <stdlib.h>


class convertor
{
	double firstValue;
	double normalizedValue;
	double calculatedValue;
	int primalUnit;
	int desiredUnit;

	double convertToMeters(double value, int option);
	void displayUnit(int optionNumber);

public:
	void enter2(double fValue, int pUnit, int dUnit);
	double getFirstValue() const;
	double getCalculatedValue() const;
	void checkUnitOption(unsigned short int &unit) const;
	void enterNumber(double& value, std::string title);
	void enterNumber(unsigned short int& value, std::string title);
};

#endif
