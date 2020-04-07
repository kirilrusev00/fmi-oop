#ifndef MONITOR_H
#define MONITOR_H

#include <iostream>

class Monitor
{
private:
	char* number;
	int height;
	int width;
public:
	Monitor();
	Monitor(const Monitor&);
	Monitor& operator=(const Monitor&);

	bool operator<(const Monitor&);

	friend std::ostream& operator<<(std::ostream&, const Monitor&);

	void setNumber(const char*);
	void setHeight(int);
	void setWidth(int);

	char* getNumber() const;

	friend class PC;

	~Monitor();
};


#endif