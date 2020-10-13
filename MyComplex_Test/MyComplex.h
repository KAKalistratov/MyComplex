#pragma once
#include <iostream>

using namespace std;

class MyComplex
{
private:
	double re;
	double im;
public:
	MyComplex(); // �����������, ��������� 0
	MyComplex(double re, double im = 0); //�����������, ��������� ����������� ����� � ���� re + im * i
	friend ostream& operator<<(ostream& out, const MyComplex& c); // �������� ������
	friend istream& operator>>(istream& in, MyComplex& c); // �������� �����
	MyComplex conj(); // �����, ������������ ����������-����������� �����
	MyComplex operator+(const MyComplex& c) const; // �������� +
	MyComplex operator-(const MyComplex& c) const; // �������� -
	friend MyComplex operator+(const double& x, const MyComplex& c); // �������� + ��� ��������������� � ������������ �����
	friend MyComplex operator-(const double& x, const MyComplex& c); // �������� - ��� ��������������� � ������������ �����
	MyComplex operator*(const MyComplex& c) const; // �������� *
	friend MyComplex operator*(const double& x, const MyComplex& c); // �������� * ��� ��������������� � ������������ �����
	MyComplex& operator=(const MyComplex& c); // �������� ������������
	MyComplex operator/(const MyComplex& c) const; // �������� /
	friend MyComplex operator/(const double& x, const MyComplex& c); // �������� / ��� ��������������� � ������������ �����
	double ABS(); // �����, ������������ ������ ������������ �����
	bool operator==(const MyComplex& c) const; // �������� ==
	bool operator!=(const MyComplex& c) const; // �������� !=
	friend bool operator== (const double& x, const MyComplex& c); // �������� == ��� ��������������� � ������������ �����
	friend bool operator!= (const double& x, const MyComplex& c); // �������� != ��� ��������������� � ������������ �����
	MyComplex operator+() const; // ������� +
	MyComplex operator-() const; // ������� -
	// ���, ��� ����, ������� �� 09.10.20

	double ARG(); // �����, ������������ �������� ������������ ����� (� ��������) � ��������� [-Pi, Pi]
	static MyComplex polar(double r, double grad); // ����������� (�����), ��������� ����������� ����� �� ��� ������ (r) � ��������� (grad). �������� �������� � ��������!
	MyComplex POW(int k); // �����, ���������� ����������� ����� � ������������� ������� k (k > 0)! ��� ������������� ������� ������� ��������� �� ������ � �������������� �����.
	MyComplex SQRT(); // �����, ������������ ���� �� ���������� ������ ������������ �����
	MyComplex operator+=(const MyComplex& c); // �������� +=
	friend MyComplex operator+=(const double& x, MyComplex& c); // �������� += ��� ������������� += ������������ �����
	MyComplex operator-=(const MyComplex& c); // �������� -=
	friend MyComplex operator-=(const double& x, MyComplex& c); // �������� -= ��� ������������� += ������������ �����
	MyComplex operator*=(const MyComplex& c); // �������� *=
	friend MyComplex operator*=(const double& x, MyComplex& c); // �������� *= ��� ������������� += ������������ �����
	MyComplex operator/=(const MyComplex& c); // �������� /=
	friend MyComplex operator/=(const double& x, MyComplex& c); // �������� /= ��� ������������� += ������������ �����

};

