#ifndef ENTITY_H
#define ENTITY_H
#include "Point2D.h"
#include "Point3D.h"
#include <string>

static int new_id = 0;//to give unique id number to every entity

class Entity
{
public:
	enum type
	{
		entity,
		player,
		npc,
		mob
	};
	
	void setName(const std::string&);
	void setLocation(const Point2D*);
	
	const std::string getName() const;
	const Point2D* getLocation() const;
	const type getType() const;

	virtual const bool isAlive() const;
	const double getDistanceTo2D(const Entity&) const;
	const double getDistanceTo(const Entity&) const;
	void moveTo(const Point2D*);
	void moveTo(const Entity&);

	virtual std::ostream& print(std::ostream&) const = 0;

	~Entity();
protected:
	const int id;
	std::string name;
	Point2D* location;
	type type_of_class;

	Entity();
	Entity(type);
	Entity(const Entity&);
	Entity& operator=(const Entity&);
};

std::ostream& operator<<(std::ostream&, const Entity::type&);
std::ostream& operator<<(std::ostream&, const Entity&);

#endif