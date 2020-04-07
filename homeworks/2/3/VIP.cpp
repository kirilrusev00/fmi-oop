#include "VIP.h"
#include <cstring>

void VIP::setTitle(const char* newTitle)
{
	delete[] title;
	int length = strlen(newTitle) + 1;
	title = new char[length];
	strcpy_s(title, length, newTitle);
}

std::ostream& operator<<(std::ostream& out, const VIP& vip)
{
	out << "VIP\t" << "Username: " << vip.getUsername()
		<< "\tTitle: " << vip.getTitle() << "\n";
	return out;
}