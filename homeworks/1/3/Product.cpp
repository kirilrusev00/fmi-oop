#include "Product.h"
#include <iostream>
#include <cstring>

const int MAX_SIZE = 30;//Default size of dynamic array

Product::Product() :price(0), display_size(0), count(0)
{
	SKU = new char[MAX_SIZE];
	SKU[0] = '\0';
	brand = new char[MAX_SIZE];
	brand[0] = '\0';
	model = new char[MAX_SIZE];
	model[0] = '\0';
	colour = new char[MAX_SIZE];
	colour[0] = '\0';
}

Product::Product(const Product& rhs) :price(rhs.price), display_size(rhs.display_size), count(rhs.count)
{
	int size = strlen(rhs.SKU);
	SKU = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		SKU[i] = rhs.SKU[i];
	}
	
	size = strlen(rhs.brand);
	brand = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		brand[i] = rhs.brand[i];
	}
	
	size = strlen(rhs.model);
	model = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		model[i] = rhs.model[i];
	}
	
	size = strlen(rhs.colour);
	colour = new char[size + 1];
	for (int i = 0; i <= size; i++)
	{
		colour[i] = rhs.colour[i];
	}
}

Product& Product::operator=(const Product& rhs)
{
	if (this != &rhs)
	{
		delete[] SKU;
		delete[] brand;
		delete[] model;
		delete[] colour;

		price = rhs.price;
		display_size = rhs.display_size;
		count = rhs.count;

		int size = strlen(rhs.SKU);
		SKU = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			SKU[i] = rhs.SKU[i];
		}
		
		size = strlen(rhs.brand);
		brand = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			brand[i] = rhs.brand[i];
		}
		
		size = strlen(rhs.model);
		model = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			model[i] = rhs.model[i];
		}
		
		size = strlen(rhs.colour);
		colour = new char[size + 1];
		for (int i = 0; i <= size; i++)
		{
			colour[i] = rhs.colour[i];
		}
	}
	return *this;
}

char* Product::getSKU() const 
{ 
	return SKU; 
}
void Product::setSKU(const char* newSKU) 
{ 
	delete[] SKU;
	int size = strlen(newSKU);
	SKU = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		SKU[i] = newSKU[i];
	} 
}

char* Product::getBrand() const 
{ 
	return brand; 
}
void Product::setBrand(const char* newBrand) 
{
	delete[] brand;
	int size = strlen(newBrand);
	brand = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		brand[i] = newBrand[i];
	}
}

char* Product::getModel() const 
{ 
	return model; 
}
void Product::setModel(const char* newModel) 
{
	delete[] model;
	int size = strlen(newModel);
	model = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		model[i] = newModel[i];
	}
}

char* Product::getColour() const 
{ 
	return colour; 
}
void Product::setColour(const char* newColour) 
{
	delete[] colour;
	int size = strlen(newColour);
	colour = new char[size + 1];
	for (int i = 0; i < size; i++)
	{
		colour[i] = newColour[i];
	}
}

double Product::getPrice() const 
{ 
	return price; 
}
void Product::setPrice(const double newPrice) 
{ 
	price = newPrice; 
}

double Product::getDisplaySize() const 
{ 
	return display_size; 
}
void Product::setDisplaySize(const double newDisplaySize) 
{ 
	display_size = newDisplaySize; 
}

int Product::getCount() const 
{ 
	return count; 
}
void Product::setCount(const int newCount) 
{ 
	price = newCount; 
}

void Product::input()
{
	std::cout << "Enter SKU:";
	std::cin >> SKU;
	std::cout << "Enter brand:";
	std::cin >> brand;
	std::cout << "Enter model:";
	std::cin >> model;
	std::cout << "Enter colour:";
	std::cin >> colour;
	std::cout << "Enter price:";
	std::cin >> price;
	std::cout << "Enter display size:";
	std::cin >> display_size;
	std::cout << "Enter count:";
	std::cin >> count;
}

Product::~Product()
{
	delete[] SKU;
	delete[] brand;
	delete[] model;
	delete[] colour;
}