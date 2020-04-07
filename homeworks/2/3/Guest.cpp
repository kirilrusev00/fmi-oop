#include "Guest.h"
#include <cstring>

Guest::Guest()
{
	ip_address = new char[1];
	ip_address[0] = '\0';
}

Guest::Guest(const Guest& rhs)
{
	int length = strlen(rhs.getIPAddress()) + 1;
	ip_address = new char[length];
	strcpy_s(ip_address, length, rhs.getIPAddress());
}

Guest& Guest::operator=(const Guest& rhs)
{
	if (this != &rhs)
	{
		setIPAddress(rhs.getIPAddress());
	}
	return *this;
}

const char* Guest::getIPAddress() const
{
	return ip_address;
}
void Guest::setIPAddress(const char* newIPAddress)
{
	delete[] ip_address;
	int length = strlen(newIPAddress) + 1;
	ip_address = new char[length];
	strcpy_s(ip_address, length, newIPAddress);
}

std::ostream& operator<<(std::ostream& out, const Guest& guest)
{
	out << "Guest\t" << "IP Address:" << guest.getIPAddress() << "\n";

	return out;
}

Guest::~Guest()
{
	delete[] ip_address;
}