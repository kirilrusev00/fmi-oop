#include "PowerUser.h"
#include <iostream>

PowerUser::PowerUser(): reputation(0)
{
}

const int PowerUser::getReputation() const
{
	return reputation;
}

void PowerUser::earn_reputation(const User& other_user)
{
	if (this == &other_user)
	{
		std::cout << "The users cannot give reputation to themselves!\n";
	}
	else
	{
		reputation++;
	}
}

std::ostream& operator<<(std::ostream& out, const PowerUser& power_user)
{
	out<<"Power User\t" << "Username: " << power_user.getUsername()
		<< "\tTitle: " << power_user.getTitle()
		<< "\tReputation: " << power_user.getReputation() << "\n";
	return out;
}