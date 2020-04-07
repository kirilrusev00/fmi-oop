#include "PC.h"
#include <cstring>

LinkedMonitors::LinkedMonitors()
{
	next = nullptr;
}

LinkedMonitors::LinkedMonitors(const Monitor& rhs)
{
	m = rhs;
	next = nullptr;
}

PC::PC()
{
	number = 0;
	size_list = 10;
	list = new LinkedMonitors[size_list];
	list[0] = LinkedMonitors();
	serial_number = new char[size_list];
	serial_number[0] = '\0';
}

PC::PC(const PC& rhs)
{
	size_list = rhs.size_list;
	list = new LinkedMonitors[size_list];
	number = rhs.number;
	for (int i = 0; i < number; i++)
	{
		list[i] = rhs.list[i];
	}
	int size = strlen(rhs.serial_number) + 1;
	serial_number = new char[size];
	for (int i = 0; i < size; i++)
	{
		serial_number[i] = rhs.serial_number[i];
	}
}

PC& PC::operator=(const PC& rhs)
{
	if (this != &rhs)
	{
		delete[] list;
		delete[] serial_number;
		
		size_list = rhs.size_list;
		list = new LinkedMonitors[size_list];
		number = rhs.number;
		for (int i = 0; i < number; i++)
		{
			list[i] = rhs.list[i];
		}
		int size = strlen(rhs.serial_number) + 1;
		serial_number = new char[size];
		for (int i = 0; i < size; i++)
		{
			serial_number[i] = rhs.serial_number[i];
		}
	}
	return *this;
}

Monitor PC::operator[](int ind)
{
	if (ind >= 0 && ind < number)
	{
		return list[ind].m;
	}
	else return Monitor();
}

void PC::resize()
{
	if (number != 0)
	{
		LinkedMonitors* newList = new LinkedMonitors[size_list * 2];
		for (int i = 0; i < number; i++)
		{
			newList[i] = list[i];
		}
		delete[] list;
		list = newList;
		size_list *= 2;
	}
	else
	{
		LinkedMonitors* newList = new LinkedMonitors[1];
		delete[] list;
		list = newList;
		size_list = 1;
	}
}

bool PC::is_full() const
{
	return (size_list == (number+1));
}

void PC::add_monitor(const Monitor& new_monitor)
{
	if (is_full())
	{
		resize();
	}
	if (number == 0)
	{
		list[number].m = new_monitor;
	}
	else
	{
		*list[number-1].next = new_monitor;
		LinkedMonitors link = LinkedMonitors(new_monitor);
		list[number] = link;
	}
	number++;
}

bool PC::find_monitor(const char* name) const
{
	for (int ind = 0; ind < number; ind++)
	{
		int size_number = strlen(list[ind].m.number);
		int size_name = strlen(name);
		if (size_number == size_name)
		{
			bool is_true = true;
			for (int j = 0; j < size_name; j++)
			{
				if (list[ind].m.number[j] != name[j])
				{
					is_true = false;
					break;
				}
			}
			if (is_true = true)
			{
				return true;
			}
		}
	}
	return false;
}

void PC::print() const
{
	for (int i = 0; i < number; i++)
	{
		std::cout << "Monitor " << i << ":\n";
		std::cout << list[i].m;
	}
}

PC::~PC()
{
	delete[] list;
	delete[] serial_number;
}