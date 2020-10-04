#include "MyComplex.h"
#include <iostream>

using namespace std;

int main()
{
	MyComplex a(1, 5);
	MyComplex b;
	cout << a.conj();
	return 0;
}