#ifndef GUEST_H
#define GUEST_H
#include <iostream>

class Guest
{
private:
	char* ip_address;

public:
	Guest();
	Guest(const Guest&);
	Guest& operator=(const Guest&);

	const char* getIPAddress() const;
	void setIPAddress(const char*);

	friend std::ostream& operator<<(std::ostream& out, const Guest&);

	~Guest();
};

#endif