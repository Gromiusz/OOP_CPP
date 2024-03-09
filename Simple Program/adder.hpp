#pragma once
#include <cmath>
#include <string>
#include <iostream>

class geom
{
	double a1;
	double q;
	double an;
	double sn;
	int n;


public:
	//geom(double a11, double qq);
	void set_a1(double inputValue);
	void set_q(double inputValue);
	void set_n(int inputValue);
	void set_an();
	void set_sn();
	void calculate();
	
	void enterNumber(double& value, std::string title);
	void enterNumber(int& value, std::string title);
	void print_an();
	void print_sn();
};
