#include "adder.hpp"

//geom::geom(double a11, double qq) : a1(a11), q(qq)
//{

//}

void geom::set_a1(double inputValue)
{
	a1 = inputValue;
}
void geom::set_q(double inputValue)
{
	q = inputValue;
}
void geom::set_n(int inputValue)
{
	n = inputValue;
}

void geom::set_an()
{
	an = a1 * pow(q, n - 1);
}
void geom::set_sn()
{
	if (q == 1)
	{
		sn = n * a1;
	}
	else
	{
		sn = a1 * (1 - pow(q, n)) / (1 - q);
	}
}
void geom::enterNumber(double& value, std::string title)
{
	while (true) {
		std::cout << title;
		if (std::cin >> value) {
			break;
		}
		else {
			std::cout << "Not a number. Please try again." << std::endl;
			std::cin.clear(); 
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}
void geom::enterNumber(int& value, std::string title)
{
	while (true) {
		std::cout << title;
		if (std::cin >> value && value>0) {
			break;
		}
		else {
			std::cout << "Not an int. Please try again." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}

void geom::print_an()
{
	std::cout << "an = " << an << '\n';
}
void geom::print_sn()
{
	std::cout << "sn = " << sn << '\n';
}
void geom::calculate()
{
	set_an();
	set_sn();
}
