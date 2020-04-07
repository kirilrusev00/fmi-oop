#include "User.h"
#include <cstring>
#include <iostream>

User::User()
{
	username = new char[1];
	username[0] = '\0';
	password = new char[1];
	password[0] = '\0';
	title = new char[1];
	title[0] = '\0';
}

User::User(const User& rhs)
{
	int length = strlen(rhs.getUsername()) + 1;
	username = new char[length];
	strcpy_s(username, length, rhs.getUsername());

	length = strlen(rhs.getPassword()) + 1;
	password = new char[length];
	strcpy_s(password, length, rhs.getPassword());

	length = strlen(rhs.getTitle()) + 1;
	title = new char[length];
	strcpy_s(title, length, rhs.getTitle());
}

User& User::operator=(const User& rhs)
{
	if (this != &rhs)
	{
		delete[] username;
		delete[] title;

		int length = strlen(rhs.getUsername()) + 1;
		username = new char[length];
		strcpy_s(username, length, rhs.getUsername());

		length = strlen(rhs.getTitle()) + 1;
		title = new char[length];
		strcpy_s(title, length, rhs.getTitle());

		setPassword(rhs.getPassword());
	}
	return *this;
}

//Addition crypt
void User::crypt_password(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] += 2;
	}
}

const char* User::getUsername() const
{
	return username;
}

const char* User::getPassword() const
{
	return password;
}

const char* User::getTitle() const
{
	return title;
}

void User::setPassword(const char* newPassword)
{
	delete[] password;
	int length = strlen(newPassword) + 1;
	password = new char[length];
	strcpy_s(password, length, newPassword);
	crypt_password(password);
}
/*
void User::change_password()
{
	char* old_password = new char[31];
	std::cout << "Enter your old password: ";
	std::cin >> old_password;
	crypt_password(old_password);
	if (are_strings_equal(password, old_password))
	{
		std::cout << "Enter new password: ";
		char* new_password = new char[31];
		std::cin >> new_password;
		setPassword(new_password);
		std::cout << "Password changed successfully\n";
	}
	else
	{
		std::cout << "Wrong password!\n";
	}
}
*/
void User::change_password(const char* oldPassword, const char* newPassword)
{
	if (is_string_equal_to_password(oldPassword))
	{
		setPassword(newPassword);
		std::cout << "Password changed successfully\n";
	}
	else
	{
		std::cout << "Wrong password!\n";
	}
}

bool User::is_string_equal_to_password(const char* str)
{
	if (strlen(getPassword()) != strlen(str))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < strlen(str); i++)
		{
			if (getPassword()[i] != (str[i] + 2))
			{
				return false;
			}
		}
	}
	return true;
}

/*
bool User::are_strings_equal(const char* str1, const char* str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return false;
	}
	else
	{
		for (int i = 0; i < strlen(str1); i++)
		{
			if (str1[i] != str2[i])
			{
				return false;
			}
		}
	}
	return true;
}
*/

std::ostream& operator<<(std::ostream& out, const User& user)
{
	out << "User\t" << "Username: " << user.getUsername()
		<< "\tTitle: " << user.getTitle() << "\n";
	
	return out;
}

User::~User()
{
	delete[] username;
	delete[] password;
	delete[] title;
}