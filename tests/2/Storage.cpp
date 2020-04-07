#include "Storage.h"
#include <cstring>
#include <iostream>
/*
Storage::Storage():max_capacity(0),taken_capacity(0)
{
	hash_code = new char[0];
	name = new char[0];
}
*/
Storage::Storage(double set_max_capacity, double set_taken_capacity, const char* set_hash_code, const char* set_name)
{
	max_capacity = set_max_capacity;
	taken_capacity = set_taken_capacity;
	int length = strlen(set_hash_code) + 1;
	hash_code = new char[length];
	strcpy_s(hash_code, length, set_hash_code);
	length = strlen(set_name) + 1;
	name = new char[length];
	strcpy_s(name, length, set_name);
}

Storage::Storage(const Storage& rhs) : max_capacity(rhs.max_capacity), taken_capacity(rhs.taken_capacity)
{
	int length = strlen(rhs.hash_code) + 1;
	hash_code = new char[length];
	strcpy_s(hash_code, length, rhs.hash_code);
	length = strlen(rhs.name) + 1;
	name = new char[length];
	strcpy_s(name, length, rhs.name);
}
Storage& Storage::operator=(const Storage& rhs)
{
	if (this != &rhs)
	{
		setHashCode(rhs.hash_code);
		setName(rhs.name);
		setMaxCapacity(rhs.max_capacity);
		setTakenCapacity(rhs.taken_capacity);
	}
	return *this;
}

const char* Storage::getHashCode() const
{
	return hash_code;
}
const char* Storage::getName() const
{
	return name;
}
const double Storage::getMaxCapacity() const
{
	return max_capacity;
}
const double Storage::getTakenCapacity() const
{
	return taken_capacity;
}

void Storage::setHashCode(const char* newHashCode)
{
	delete[] hash_code;
	int length = strlen(newHashCode) + 1;
	hash_code = new char[length];
	strcpy_s(hash_code, length, newHashCode);
}
void Storage::setName(const char* newName)
{
	delete[] name;
	int length = strlen(newName) + 1;
	name = new char[length];
	strcpy_s(name, length, newName);
}
void Storage::setMaxCapacity(const double& newMaxCapacity)
{
	max_capacity = newMaxCapacity;
}
void Storage::setTakenCapacity(const double& newTakenCapacity)
{
	if (newTakenCapacity <= getMaxCapacity())
	{
		taken_capacity = newTakenCapacity;
	}
	else
	{
		std::cout << "The maximum capacity is " << getMaxCapacity() << "!\n";
	}
}

Storage::~Storage()
{
	delete[] hash_code;
	delete[] name;
}
