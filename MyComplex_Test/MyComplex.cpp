#include "MyComplex.h"

MyComplex::MyComplex()
{
	this->re = 0;
	this->im = 0;
}

MyComplex::MyComplex(double re, double im)
{
	this->re = re;
	this->im = im;
}

MyComplex MyComplex::conj()
{
    return MyComplex(re, -im);
}

MyComplex MyComplex::operator+(const MyComplex& c) const
{
    return MyComplex(re + c.re, im + c.im);
}

MyComplex MyComplex::operator-(const MyComplex& c) const
{
    return MyComplex(re - c.re, im - c.im);
}

MyComplex MyComplex::operator*(const MyComplex& c) const
{
    return MyComplex(re * c.re - im * c.im, im * c.re + re * c.im);
}

MyComplex MyComplex::operator=(const MyComplex& c)
{
    return MyComplex(c.re, c.im);
}

MyComplex MyComplex::operator/(const MyComplex& c) const
{
    return MyComplex((re * c.re + im * c.im) / (c.re * c.re + c.im * c.im), (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im));
}

double MyComplex::ABS()
{
    return sqrt(re * re + im * im);
}

bool MyComplex::operator==(const MyComplex& c) const
{
    if (re == c.re && im == c.im) { return true; }
    else { return false; }
}

bool MyComplex::operator!=(const MyComplex& c) const
{
    if (re != c.re && im != c.im) { return true; }
    else { return false; }
}

MyComplex MyComplex::operator+() const
{
    return MyComplex(re, im);
}

MyComplex MyComplex::operator-() const
{
    return MyComplex(-re, -im);
}

ostream& operator<<(ostream& out, const MyComplex& c)
{
    if (c.re == 0 && c.im == 0) { out << 0; }
    else if (c.im == 0) { out << c.re; }
    else if (c.re == 0) 
    {
        if (c.im == 1) { out << "i"; }
        else if (c.im == -1) { out << "-i"; }
        else { out << c.im << "i"; }
    }
    else 
    {
        if (c.im == 1) { out << c.re << "+i"; }
        else if (c.im == -1) { out << c.re << "-i"; }
        else if (c.im > 0) { out << c.re << "+" << c.im << "i"; }
        else { out << c.re << c.im << "i"; }
    }
    out << endl;
    return out;
}

istream& operator>>(istream& in, MyComplex& c)
{
    in >> c.re >> c.im;
    return in;
}

MyComplex operator+(const double& x, const MyComplex& c)
{
    return MyComplex(x + c.re, c.im);
}

MyComplex operator-(const double& x, const MyComplex& c)
{
    return MyComplex(x - c.re, -c.im);
}

MyComplex operator*(const double& x, const MyComplex& c)
{
    return MyComplex(x * c.re, x * c.im);
}

MyComplex operator/(const double& x, const MyComplex& c)
{
    MyComplex y(x);
    return y / c;
}

bool operator==(const double& x, const MyComplex& c)
{
    if (x == c.re && c.im == 0) { return true; }
    else { return false; }
}

bool operator!=(const double& x, const MyComplex& c)
{
    if (x != c.re || c.im != 0) { return true; }
    else { return false; }
}
