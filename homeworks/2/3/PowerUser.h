#ifndef POWERUSER_H
#define POWERUSER_H
#include "User.h"

class PowerUser :virtual public User
{
private:
	int reputation;
public:
	PowerUser();

	const int getReputation() const;

	void earn_reputation(const User&);

	friend std::ostream& operator<<(std::ostream& out, const PowerUser&);
};

#endif