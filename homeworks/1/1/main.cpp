#include "IntStack.h"
#include <iostream>

int main()
{
	IntStack s1;
	s1.print();
	for (int i = 15; i >= 1; i--)
	{
		if (i % 2 == 0)
		{
			s1.push_back(i);
		}
		else s1.push_back(-i);
	}
	s1.print();

	IntStack s2(sortStack(s1));
	s2.print();

	IntStack s3 = sortStack(s1);
	s3.print();
	s1.print();
	
	s1[6] = 20;
	s1.print();

	IntStack s4;
	IntStack s5 = sortStack(s4);
	s5.print();

	IntStack s6;
	for (int i = 0; i < 10; i++)
	{
		s6.input();
	}
	s6.print();

	system("pause");
	return 0;
}