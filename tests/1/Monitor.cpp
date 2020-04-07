#include "Monitor.h"
#include <cstring>
#include <iostream>

Monitor::Monitor():height(0),width(0)
{
	number = new char[1];
	number[0] = '\0';
}

Monitor::Monitor(const Monitor& rhs) :height(rhs.height), width(rhs.width)
{
	int size = strlen(rhs.number) + 1;
	number = new char[size];
	for (int i = 0; i < size; i++)
	{
		number[i] = rhs.number[i];
	}
}


Monitor& Monitor::operator=(const Monitor& rhs)
{
	if (this != &rhs)
	{
		delete[] number;
		int size = strlen(rhs.number) + 1;
		number = new char[size];
		for (int i = 0; i < size; i++)
		{
			number[i] = rhs.number[i];
		}
		height = rhs.height;
		width = rhs.width;
	}
	return *this;
}

bool Monitor::operator<(const Monitor&rhs)
{
	if (width != rhs.width)
	{
		return width < rhs.width;
	}
	else return height < rhs.height;
}

void Monitor::setNumber(const char* newNumber)
{ 
	delete[] number;
	int size = strlen(newNumber) + 1;
	number = new char[size];
	for (int i = 0; i < size; i++)
	{
		number[i] = newNumber[i];
	}
}

void Monitor::setHeight(int newHeight) 
{ 
	height = newHeight;
}

void Monitor::setWidth(int newWidth)
{
	width = newWidth;
}

char* Monitor::getNumber() const
{
	return number;
}

std::ostream& operator<<(std::ostream& out, const Monitor& rhs)
{
	std::cout << "Serial number: ";
	out << rhs.number;
	std::cout << std::endl;
	std::cout << "Height: ";
	out << rhs.height;
	std::cout << " pixels\n";
	std::cout << "Width: ";
	out << rhs.width;
	std::cout << " pixels\n";
	return out;
}


Monitor::~Monitor()
{
	delete[] number;
}