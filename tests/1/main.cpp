#include "Monitor.h"
#include "PC.h"
#include <iostream>

int main()
{
	Monitor m1;
	m1.setNumber("001");
	m1.setWidth(20);
	m1.setHeight(50);
	
	Monitor m2;
	m1.setNumber("002");
	m1.setWidth(300);
	m1.setHeight(1000);

	PC pc1;
	pc1.add_monitor(m1);
	pc1.add_monitor(m2);
	std::cout << pc1.find_monitor(m1.getNumber()) << std::endl;
	pc1.print();


	system("pause");
	return 0;
}