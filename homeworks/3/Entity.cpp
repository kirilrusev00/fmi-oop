#include "Entity.h"

Entity::Entity() : id(new_id++)
{
	name = '\0';
	location = new Point2D();
	type_of_class = entity;
}

Entity::Entity(type _type_of_class) : id(new_id++), type_of_class(_type_of_class)
{
	name = '\0';
	location = new Point2D();
}

//the id must be unique, so it is different than that in rhs
Entity::Entity(const Entity& rhs) : id(new_id++), type_of_class(rhs.type_of_class), name(rhs.name)
{
	location = rhs.location;
}

//the id must be unique, so it does not change
Entity& Entity::operator=(const Entity& rhs)
{
	if (this != &rhs)
	{
		type_of_class = rhs.type_of_class;
		setName(rhs.name);
		setLocation(rhs.location);
	}
	return *this;
}

void Entity::setName(const std::string& newName)
{
	name = newName;
}
void Entity::setLocation(const Point2D* newLocation)
{
	delete location;
	if (newLocation->getPointType() == "_2d")
	{
		location = new Point2D;
		*location = *newLocation;
	}
	else
	{
		location = new Point3D(*dynamic_cast<Point3D*>(const_cast<Point2D*>(newLocation)));
	}
}

const std::string Entity::getName() const
{
	return name;
}
const Point2D* Entity::getLocation() const
{
	return location;
}
const Entity::type Entity::getType() const
{
	return type_of_class;
}

const bool Entity::isAlive() const
{
	return true;
}
const double Entity::getDistanceTo2D(const Entity& rhs) const
{
	return location->getDistanceTo(*rhs.getLocation());
}
const double Entity::getDistanceTo(const Entity& rhs) const
{
	if (location->getPointType() == "_3d" && rhs.location->getPointType() == "_3d")
	{
		Point3D* point1 = dynamic_cast<Point3D*>(location);
		Point3D* point2 = dynamic_cast<Point3D*>(rhs.location);
		return point1->getDistanceTo(*point2);
	}
	else
	{
		Point2D* point1 = location;
		Point2D* point2 = rhs.location;
		return point1->Point2D::getDistanceTo(*point2);
	}
}

void Entity::moveTo(const Point2D* _point)
{
	if (location->getPointType() == _point->getPointType())
	{
		setLocation(_point);
	}
	else
	{
		location->setX(_point->getX());
		location->setY(_point->getY());
	}
}
void Entity::moveTo(const Entity& rhs)
{
	moveTo(rhs.location);
}

Entity::~Entity()
{
	delete[] location;
}

std::ostream& operator<<(std::ostream& out, const Entity::type& _type)
{
	if (_type == Entity::entity)
	{
		out << "entity";
	}
	if (_type == Entity::player)
	{
		out << "player";
	}
	if (_type == Entity::npc)
	{
		out << "npc";
	}
	if (_type == Entity::mob)
	{
		out << "mob";
	}
	return out;
}

std::ostream& operator<<(std::ostream& out, const Entity& ent)
{
	return ent.print(out);
}