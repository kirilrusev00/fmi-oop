#include "Circle.h"

Circle::Circle() :Figure(circle), radius(0)
{
}
Circle::Circle(Point _point, int _radius, std::string _fill) :
	Figure(circle, _point, _fill), radius(_radius)
{
}

void Circle::setRadius(const int& newRadius)
{
	radius = newRadius;
}

const int Circle::getRadius() const
{
	return radius;
}

//check if this circle is within a rectangle {min_x <= x <= max_x; min_y <= y <= max_y}
bool Circle::within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const
{
	//the limits for the coordinates of a point (x,y) in this circle:
	//left_circle <= x <= right_circle and top_circle <= y <= bottom_circle
	int left_circle = point.getX() - getRadius();
	int right_circle = point.getX() + getRadius();
	int top_circle = point.getY() - getRadius();
	int bottom_circle = point.getY() + getRadius();

	return ((left_circle >= min_x) && (right_circle <= max_x)
		&& (top_circle >= min_y) && (bottom_circle <= max_y));
}

//check if this circle is within another circle with centre (x_centre, y_centre) and radius _radius
bool Circle::within_circle(const int& x_centre, const int& y_centre, const int& _radius) const
{
	Point centre(x_centre, y_centre);

	return ((centre.getDistanceTo(point) + radius) <= _radius);
}

std::ostream& Circle::print(std::ostream& out) const
{
	out << getType() << " " << getPoint() << " " << getRadius() << " " << getFill() << "\n";
	return out;
}
/*
std::istream& Circle::input(std::istream& in)
{
	in >> point;

	int set_radius;
	in >> set_radius;

	setRadius(set_radius);

	return in;
}
*/