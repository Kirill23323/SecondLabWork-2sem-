#include "Complex.h"
#include <iostream>

double TComplex::GetRe()
{
	return re;
}

void TComplex::SetRe(double _re)
{
	re = _re;
}

double TComplex::GetIm()
{
	return im;
}

void TComplex::SetIm(double _im)
{
	im = _im;
}

TComplex::TComplex(const TComplex & c)
{
	re = c.re;
	im = c.im;
}

TComplex::TComplex(double re, double im)
{
	this->re = re;
	this->im = im;
}

TComplex TComplex::operator+(TComplex & B)
{
	TComplex sum;
	sum.re = re + B.re;
	sum.im = im + B.im;
	return sum;
}

TComplex TComplex::operator-(TComplex & B)
{
	TComplex minus;
	minus.re = re - B.re;
	minus.im = im - B.im;
	return minus;
}

TComplex TComplex::operator*(TComplex & B)
{
	TComplex mult;
	mult.re = (re * B.re) - (im * B.re);
	mult.im = (re * B.im) + (B.re * im);
	return mult;
}

TComplex TComplex::operator/(TComplex & B)
{
	TComplex del;
	del.re = (re * B.re + im * B.im) / (B.re * B.re - B.im * B.im);
	del.im = (im * B.re - re * B.im) / (B.re * B.re - B.im * B.im);
	return del;
}

TComplex & TComplex::operator=(const TComplex & B)
{
	this->re = B.re;
	this->im = B.im;
	return *this;
}

bool  TComplex::operator==(TComplex & B)
{
	if ((B.re == re) && (B.im == im)) 
	{

		return true;
	}
	else 
	{
		return false;
	}

}

TComplex::TComplex()
{
	re = 0;
	im = 0;
}

void TComplex::GetComplexAbs()
{
	double result = sqrt(re * re + im * im);
	std::cout << "ComplexAbs =	" << result << std::endl;

}

void TComplex::TrigonometricForm()
{
	double r = sqrt(re * re + im * im);
	double fiRe = acos(re / r);
	double fiIm = asin(im / r);
	std:: cout << r << " * (cos " << fiRe << " + i * sin " << fiIm << " )" << std::endl;
}

void TComplex::DegreeOfNumber()
{
	std::cout << "В какую степень хотите возвести число?" << std::endl;
	std::cout << " 1 - целую" << std::endl;
	std::cout << " 2 - В дробную" << std::endl;
	int n;
	std::cin >> n;
	if (n == 1)
	{
		std::cout << " Введите целое число" << std::endl;
		int a;
		std::cin >> a;
		double r = sqrt(re * re + im * im);
		double fiRe = acos(re / r);
		double fiIm = asin(im / r);
		std::cout << pow(r, a) << " * (cos " << fiRe * a << " + i * sin " << fiIm * a << ")" << std::endl;
	}
	else if (n == 2)
	{
		std::cout << " Введите дробное число" << std::endl;
		double a;
		std::cin >> a;
		double r = sqrt(re * re + im * im);
		double fiRe = acos(re / r);
		double fiIm = asin(im / r);
		std::cout << pow(r, a) << " * (cos " << fiRe * a << " + i * sin " << fiIm * a << ")" << std::endl;
	}
}

void TComplex::ComplexDegree(TComplex& comp)
{
	TComplex t1(log(sqrt(re * re + im * im)), atan(im / re));
	t1 = t1 * comp;
	std::cout << "e ^ ( " << t1.re << " + " << "i * " << t1.im << " )" << std::endl;
}

std::ostream & operator<<(std::ostream & B, TComplex & A)
{
	B << A.re << " + i *" << A.im;
	return B;
}

std::istream  & operator>>(std::istream & B, TComplex & A)
{
	B >> A.re;
	B >> A.im;
	return B;
}
