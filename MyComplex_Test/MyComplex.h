#pragma once
#include <iostream>

using namespace std;

class MyComplex
{
private:
	double re;
	double im;
public:
	MyComplex();
	MyComplex(double re, double im = 0);
	friend ostream& operator<<(ostream& out, const MyComplex& c);
	friend istream& operator>>(istream& in, MyComplex& c);
	MyComplex conj();
	MyComplex operator+(const MyComplex& c) const;
	MyComplex operator-(const MyComplex& c) const;
	friend MyComplex operator+(const double& x, const MyComplex& c);
	friend MyComplex operator-(const double& x, const MyComplex& c);
	MyComplex operator*(const MyComplex& c) const;
	friend MyComplex operator*(const double& x, const MyComplex& c);
	MyComplex operator=(const MyComplex& c);
	MyComplex operator/(const MyComplex& c) const;
	friend MyComplex operator/(const double& x, const MyComplex& c);
	double ABS();
	bool operator==(const MyComplex& c) const;
	bool operator!=(const MyComplex& c) const;
	friend bool operator== (const double& x, const MyComplex& c); 
	friend bool operator!= (const double& x, const MyComplex& c);
	MyComplex operator+() const; 
	MyComplex operator-() const; 

};

