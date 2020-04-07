#ifndef USER_H
#define USER_H
#include "Guest.h"

class User :public Guest
{
private:
	char* username;
	char* password;

	void crypt_password(char*);
	bool is_string_equal_to_password(const char*);
	//bool are_strings_equal(const char*, const char*);
	
protected:
	char* title;

public:
	User();
	User(const User&);
	User& operator=(const User&);

	const char* getUsername() const;
	const char* getPassword() const;//Crypted password
	const char* getTitle() const;

	void setPassword(const char*);

	//void change_password();
	void change_password(const char*, const char*);

	friend std::ostream& operator<<(std::ostream&, const User&);

	~User();

	friend class Admin;
};

#endif