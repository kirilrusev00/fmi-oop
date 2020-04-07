#include "Point.h"
#include <cmath>

Point::Point() : x(0), y(0)
{
}

Point::Point(int set_x, int set_y) : x(set_x), y(set_y)
{

}

void Point::setX(const int& newX)
{
	x = newX;
}
void Point::setY(const int& newY)
{
	y = newY;
}

const int Point::getX() const
{
	return x;
}
const int Point::getY() const
{
	return y;
}


const double Point::getDistanceTo(const Point& p) const
{
	return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
}
/*
std::istream& operator>>(std::istream& in, Point& p)
{
	in >> p.x >> p.y;
	return in;
}
*/
std::ostream& operator<<(std::ostream& out, const Point& p)
{
	out << p.x << " " << p.y;
	return out;
}
