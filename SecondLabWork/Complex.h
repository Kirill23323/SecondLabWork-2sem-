#include <iostream>
class TComplex
{
private:
	double re;
	double im;
public:
	double GetRe();
	void SetRe(double _re);
	double GetIm();
	void SetIm(double _im);
	TComplex(const TComplex& c);
	TComplex(double re, double im);
	TComplex operator + (TComplex& B);
	TComplex operator - (TComplex& B);
	TComplex operator * (TComplex& B);
	TComplex operator / (TComplex& B);
	TComplex & operator = (const TComplex& B);
	bool  operator == (TComplex& B);
	friend std::ostream & operator << (std::ostream& B, TComplex& A);
	friend std::istream &  operator >> (std::istream& B, TComplex& A);
	TComplex();
	void GetComplexAbs();
	void TrigonometricForm();
	void DegreeOfNumber();
	void ComplexDegree(TComplex& comp);
};