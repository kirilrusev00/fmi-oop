#include "Admin.h"
#include <cstring>

void Admin::setUsername(const char* newUsername)
{
	delete[] username;
	int length = strlen(newUsername) + 1;
	username = new char[length];
	strcpy_s(username, length, newUsername);
}

void Admin::setUsername_of_anotherUser(User& user_with_newUsername, const char* newUsername)
{
	delete[] user_with_newUsername.username;
	int length = strlen(newUsername) + 1;
	user_with_newUsername.username = new char[length];
	strcpy_s(user_with_newUsername.username, length, newUsername);
}

std::ostream& operator<<(std::ostream& out, const Admin& admin)
{
	out << "Admin\t" << "Username: " << admin.getUsername()
		<< "\tTitle: " << admin.getTitle()
		<< "\tReputation: " << admin.getReputation() << "\n";
	return out;
}