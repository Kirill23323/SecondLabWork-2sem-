#include "Complex.h"
#include <iostream>
#include <clocale>
int main()
{
	setlocale(LC_ALL, "rus");
	TComplex com1(3, 5);
	TComplex com2;
	std::cin >> com2;
	TComplex com3 = com2;
	com1.SetRe(10);
	std::cout << com1.GetRe()<<" + i*" << com1.GetIm() << std::endl;
	com3 = com1 + com2;
	std::cout << com3 << std::endl;
	com2 = com3 - com1;
	std::cout << com2 << std::endl;
	if (com1 == com2)
		std::cout << "com1 = com2 \n" << std::endl;
	com3 = com1 * com2;
	std::cout << com3 << std::endl;
	com3 = com1 / com2;
	std::cout << com3 << std::endl;
	com1.TrigonometricForm(); // Доп задание 6
	com1.GetComplexAbs(); // Доп задание 1
	com1.DegreeOfNumber(); // Доп задания 2,3,4
	com1.ComplexDegree(com2); // Доп задание 5
	return 0;
}