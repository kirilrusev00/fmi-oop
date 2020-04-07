#ifndef PC_H
#define PC_H
#include "Monitor.h"

struct LinkedMonitors
{
	Monitor m;
	Monitor* next;

	LinkedMonitors();
	LinkedMonitors(const Monitor&);
};

class PC
{
private:
	LinkedMonitors* list;
	int number;
	char* serial_number;
	int size_list;

	bool is_full() const;
	void resize();
public:
	PC();
	PC(const PC&);
	PC& operator=(const PC&);

	Monitor operator[](int);

	void add_monitor(const Monitor&);
	bool find_monitor(const char*) const;

	void print()const;

	~PC();
};

#endif
