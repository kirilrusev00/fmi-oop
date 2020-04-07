#include "Guest.h"
#include "User.h"
#include "PowerUser.h"
#include "VIP.h"
#include "Admin.h"
#include <iostream>

int main()
{
	Guest a;
	a.setIPAddress("9080808");
	std::cout << a;

	Guest b(a);
	std::cout << b;

	User c;
	c.setPassword("aaaaa");
	std::cout << c;
	c.change_password("aaaaa", "ccc");
	std::cout << c.getPassword() << "\n";

	PowerUser d;
	std::cout << d;
	d.earn_reputation(c);
	std::cout << d;
	d.earn_reputation(d);
	std::cout << d;

	VIP e;
	std::cout << e;
	e.setTitle("lol");
	std::cout << e;

	Admin f;
	f.setUsername_of_anotherUser(f, "vipiv");
	f.setUsername_of_anotherUser(c, "notvip");
	std::cout << f;
	std::cout << c;

	system("pause");

	return 0;
}