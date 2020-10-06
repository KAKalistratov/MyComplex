#include "MyComplex.h"
#include <iostream>

using namespace std;

int main()
{
	MyComplex a(1);
	MyComplex b;
	b = a;
	cout << -b;
	return 0;
}