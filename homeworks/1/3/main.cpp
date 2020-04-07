#include <iostream>
#include <iomanip>
#include "Store.h"

void print_menu()
{
	std::cout << "A\t" << "Add new product" << std::endl;
	std::cout << "X\t" << "Delete product" << std::endl;
	std::cout << "C\t" << "Change product" << std::endl;
	std::cout << "D\t" << "Display products" << std::endl;
	std::cout << "Q\t" << "Quit" << std::endl;
}

int main()
{
	Store s1;
	char option;
	do
	{
		print_menu();
		std::cout << "Choose an option:";
		std::cin >> option;
		Product p;
		int num;
		switch (option)
		{
		case 'A':
			std::cout << "Enter a new product:" << std::endl;
			p.input();
			s1.add(p);
			break;
		case 'X':
			std::cout << "Enter the number of the product to delete:" << std::endl;
			std::cin >> num;
			s1.remove(num);
			break;
		case 'C':
			std::cout << "Enter the number of the product to change:" << std::endl;
			std::cin >> num;
			std::cout << "Enter new values to its charachteristics:" << std::endl;
			p.input();
			s1.change(num, p);
			break;
		case 'D':
			s1.print();
			break;
		case 'Q':
			break;
		default:
			std::cout << "Wrong input!\n";
		}
	} while (option != 'Q');
	
	system("pause");
	return 0;
}