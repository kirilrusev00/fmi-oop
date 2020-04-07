#ifndef VIP_H
#define VIP_H
#include "User.h"

class VIP : virtual public User
{
public:
	//VIP();

	void setTitle(const char*);

	friend std::ostream& operator<<(std::ostream& out, const VIP&);
};

#endif