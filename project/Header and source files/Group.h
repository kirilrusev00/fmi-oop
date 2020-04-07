#ifndef GROUP_H
#define GROUP_H
#include "Figure.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include <vector>

//singleton
class Group
{
private:
	std::vector<Figure*> shapes;

	Group();// default constructor
	Group(const Group&);// copy constructor
	Group& operator=(const Group&);

	int within_rect(const Rectangle&) const;
	int within_circ(const Circle&) const;
public:
	static Group &instance()
	{
		static Group *instance = new Group;
		return *instance;
	}

	const int size() const;

	void push_back(Figure*);
	bool remove(const int&);
	bool pop_back();

	Figure* operator[](const int&) const;

	int within(const Figure&) const;

	void destroyShapes();
	~Group();

	friend std::ostream& operator << (std::ostream& out, const Group& v);
};



#endif