#include "PowerUser.h"
#include "VIP.h"

class Admin : public PowerUser, public VIP
{
public:
	void setUsername(const char*);
	void setUsername_of_anotherUser(User&, const char*);

	friend std::ostream& operator<<(std::ostream& out, const Admin&);
};