#include "MagicBox.hpp"
#include <iostream>

int main()
{
	MagicBox<double> a;
	a.pop();
	for (double i = 60; i < 75; i++)
	{
		a.insert(double (i/(i+1)));
	}
	a.list();
	a.pop();
	a.list();

	MagicBox<char> b;
	for (int i = 60; i < 75; i++)
	{
		b.insert(char(i));
	}
	b.list();

	system("pause");

	return 0;
}