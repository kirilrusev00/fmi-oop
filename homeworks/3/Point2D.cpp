#include "Point2D.h"
#include <cmath>

Point2D::Point2D() :x(0), y(0)
{
}
Point2D::Point2D(double _x, double _y) : x(_x), y(_y)
{
}

void Point2D::setX(const double& newX)
{
	x = newX;
}
void Point2D::setY(const double& newY)
{
	y = newY;
}

const double Point2D::getX() const
{
	return x;
}
const double Point2D::getY() const
{
	return y;
}
const std::string Point2D::getPointType() const
{
	return "_2d";
}

double Point2D::getDistanceTo(const Point2D& other_point) const
{
	return sqrt((other_point.getX() - x)*(other_point.getX() - x) + (other_point.getY() - y)*(other_point.getY() - y));
}

std::ostream& Point2D::print(std::ostream& out) const
{
	out << "(" << x << ", " << y << ")";
	return out;
}

std::ostream& operator<<(std::ostream& out, const Point2D& _point)
{
	return _point.print(out);
}