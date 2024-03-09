#include <iostream>
#include "adder.hpp"
#include <string>

int main()
{
	double a1;
	double q;
	int n;
	geom g;

	g.enterNumber(a1, "Enter a1: ");
	g.enterNumber(q, "Enter q: ");
	g.enterNumber(n, "Enter n: ");

	g.set_n(n);
	g.set_a1(a1);
	g.set_q(q);

	g.calculate();

	g.print_an();
	g.print_sn();
}
