#include <iostream>
#include "adder.hpp"   // zła nazwa pliku


int main()
{
	date data(2,05,2023);
	date data1(31, 04, 2320);
	date data2(29, 02, 2000);
	date data3(29, 02, 2300);
	data3.printDate(); // program nie pozwoli na wyświetlenie daty dopóki nie zostanie naprawiona
	 date data4(45, 02, 2300);
	 data4.printDate();
}
