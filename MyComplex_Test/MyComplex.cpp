#include "MyComplex.h"
#include <cmath>

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

MyComplex& MyComplex::operator=(const MyComplex& c)
{
    re = c.re;
    im = c.im;
    return *this;
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

double MyComplex::ARG()
{
    double abs = ABS();
    if (abs == 0) { return 0; }
    else if (im >= 0) { return acos(re / abs); }
    else { return -acos(re / abs); }
}

MyComplex MyComplex::polar(double r, double grad)
{ 
    while (abs(grad) > 180)
    {
        grad -= 180;
        grad *= -1;
    }
    
    if (abs(grad) == 90) { return MyComplex(0, r * sin(grad * acos(-1) / 180)); }
    else if (abs(grad) == 180) { return MyComplex(r * cos(grad * acos(-1) / 180), 0); }
    else { return MyComplex(r * cos(grad * acos(-1) / 180), r * sin(grad * acos(-1) / 180)); }
}

MyComplex MyComplex::POW(int k)
{
    MyComplex RESULT = 1;
    if (k == 0) { return 1; }
    else if (k >= 1)
    {
        for (int i = 1; i <= k; i++)
        {
            RESULT = RESULT * MyComplex(re, im);
        }
        return RESULT;
    }
}

MyComplex MyComplex::SQRT()
{
    double im_tmp = sqrt((-re + ABS()) / 2);
    return MyComplex(im / (2 * im_tmp), im_tmp);
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
