#include "DNSCache.h"
#include <iostream>

int main()
{
	DNSCache c1;
	for (int i = 0; i < 3; i++)
	{
		char* name = new char[MAX_SIZE];
		std::cout << "Enter the name of Domain " << i << ":";
		std::cin >> name;
		char* ip = new char[MAX_SIZE];
		std::cout << "Enter the IP address of Domain " << i << ":";
		std::cin >> ip;
		DNSRecord a(name, ip);
		delete[] name;
		delete[] ip;
		c1.add(a);
	}
	c1.print();

	DNSCache c2;
	c2 = c1;
	//c2.flush();
	c2.print();

	DNSCache c3(c2);
	c3.print();
	char* domain=new char[MAX_SIZE];
	std::cout << "Enter a name of domain in the cache:"; 
	std::cin>>domain;
	char* address = c3.lookup(domain);
	if (address != NULL)
	{
		std::cout << address << std::endl;
	}
	else std::cout << "There is no domain with this name in the cache.\n";

	c2.flush();
	c2.print();

	delete[] domain;
	delete[] address;

	system("pause");
	return 0;
}