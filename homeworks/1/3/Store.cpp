#include "Store.h"
#include <iostream>
#include <iomanip>

Store::Store() :num(0)
{
	prod = new Product[1];
	prod[0] = Product();
}

Store::Store(const Store& rhs) :num(rhs.num)
{
	prod = new Product[num + 1];
	for (int i = 0; i < num; i++)
	{
		prod[i] = rhs.prod[i];
	}
}

Store& Store::operator=(const Store& rhs)
{
	if (this != &rhs)
	{
		delete[] prod;
		num = rhs.num;
		prod = new Product[num + 1];
		for (int i = 0; i < num; i++)
		{
			prod[i] = rhs.prod[i];
		}
	}
	return *this;
}

void Store::add(Product product)
{
	Product* newProd = new Product[num + 2];
	for (int i = 0; i < num; i++)
	{
		newProd[i] = prod[i];
	}
	newProd[num] = product;
	delete[] prod;
	prod = newProd;
	num++;
}

void Store::remove(int pos)
{
	if (pos >= 0 && pos < num)
	{
		Product* newProd = new Product[num];
		for (int i = 0; i < pos; i++)
		{
			newProd[i] = prod[i];
		}
		for (int i = pos; i < num-1	; i++)
		{
			newProd[i] = prod[i+1];
		}
		delete[] prod;
		prod = newProd;
		num--;
	}
	else
		std::cout << "Invalid position \n";
}

void Store::change(int pos, Product val)
{
	if (pos >= 0 && pos < num)
	{
		prod[pos] = val;
	}
	else
		std::cout << "Invalid position \n";
}

void Store::print() const
{
	std::cout << std::endl;
	std::cout << "|" 
		<< std::setw(5) << std::left << "No." << "|" 
		<< std::setw(11) << std::left << "SKU" << "|" 
		<< std::setw(11) << std::left << "Brand" << "|" 
		<< std::setw(11) << std::left << "Model" << "|" 
		<< std::setw(11) << std::left << "Colour" << "|" 
		<< std::setw(11) << std::left << "Price ($)" << "|" 
		<< std::setw(15) << std::left << "Display size" << "|" 
		<< std::setw(6) << std::left << "Count" << "|" << std::endl;
	for (int i = 0; i < 90; i++)
	{
		std::cout << "-";
	}
	std::cout << std::endl;
	for (int i = 0; i < num; i++)
	{
		std::cout << "|"
			<< std::setw(5) << std::left << i << "|" 
			<< std::setw(11) << std::left << prod[i].SKU << "|"
			<< std::setw(11) << std::left << prod[i].brand << "|" 
			<< std::setw(11) << std::left << prod[i].model << "|"
			<< std::setw(11) << std::left << prod[i].colour << "|" 
			<< std::setw(11) << std::left << prod[i].price << "|"
			<< std::setw(8) << std::left << prod[i].display_size << " inches|" 
			<< std::setw(6) << std::left << prod[i].count << "|" << std::endl;
	}
	std::cout << std::endl;
}

Store::~Store()
{
	delete[] prod;
}