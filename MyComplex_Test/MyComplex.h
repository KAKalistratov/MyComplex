#pragma once
#include <iostream>

using namespace std;

class MyComplex
{
private:
	double re;
	double im;
public:
	MyComplex(); // Конструктор, создающий 0
	MyComplex(double re, double im = 0); //Конструктор, создающий комплексное число в виде re + im * i
	friend ostream& operator<<(ostream& out, const MyComplex& c); // Оператор вывода
	friend istream& operator>>(istream& in, MyComplex& c); // Оператор ввода
	MyComplex conj(); // Метод, возвращающий комплексно-сопряженное число
	MyComplex operator+(const MyComplex& c) const; // Оператор +
	MyComplex operator-(const MyComplex& c) const; // Оператор -
	friend MyComplex operator+(const double& x, const MyComplex& c); // Оператор + для действительного и комплексного числа
	friend MyComplex operator-(const double& x, const MyComplex& c); // Оператор - для действительного и комплексного числа
	MyComplex operator*(const MyComplex& c) const; // Оператор *
	friend MyComplex operator*(const double& x, const MyComplex& c); // Оператор * для действительного и комплексного числа
	MyComplex& operator=(const MyComplex& c); // Оператор присваивания
	MyComplex operator/(const MyComplex& c) const; // Оператор /
	friend MyComplex operator/(const double& x, const MyComplex& c); // Оператор / для действительного и комплексного числа
	double ABS(); // метод, возвращающий модуль комплексного числа
	bool operator==(const MyComplex& c) const; // Оператор ==
	bool operator!=(const MyComplex& c) const; // Оператор !=
	friend bool operator== (const double& x, const MyComplex& c); // Оператор == для действительного и комплексного числа
	friend bool operator!= (const double& x, const MyComplex& c); // Оператор != для действительного и комплексного числа
	MyComplex operator+() const; // Унарный +
	MyComplex operator-() const; // Унарный -
	// Все, что выше, сделано до 09.10.20

	double ARG(); // метод, возвращающий аргумент комплексного числа (в радианах) в интервале [-Pi, Pi]
	static MyComplex polar(double r, double grad); // конструктор (метод), создающий комплексное число по его модулю (r) и аргументу (grad). Аргумент вводится в градусах!
	MyComplex POW(int k); // метод, возводящий комплексное число в целочисленную степень k (k > 0)! Для отрицательной степени получим сообщение об ошибке и первоначальное число.
	MyComplex SQRT(); // метод, возвращающий один из квадратных корней комплексного числа
	MyComplex operator+=(const MyComplex& c); // оператор +=
	friend MyComplex operator+=(const double& x, MyComplex& c); // оператор += для вещественного += комплексного чисел
	MyComplex operator-=(const MyComplex& c); // оператор -=
	friend MyComplex operator-=(const double& x, MyComplex& c); // оператор -= для вещественного += комплексного чисел
	MyComplex operator*=(const MyComplex& c); // оператор *=
	friend MyComplex operator*=(const double& x, MyComplex& c); // оператор *= для вещественного += комплексного чисел
	MyComplex operator/=(const MyComplex& c); // оператор /=
	friend MyComplex operator/=(const double& x, MyComplex& c); // оператор /= для вещественного += комплексного чисел

};

