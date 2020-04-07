#include "Point3D.h"
#include <cmath>

Point3D::Point3D() :z(0)
{
}
Point3D::Point3D(double _x, double _y, double _z) : Point2D(_x,_y), z(_z)
{
}

void Point3D::setZ(const double& newZ)
{
	z = newZ;
}

const double Point3D::getZ() const
{
	return z;
}
const std::string Point3D::getPointType() const
{
	return "_3d";
}

double Point3D::getDistanceTo(const Point3D& other_point) const
{
	return sqrt((other_point.getX() - x)*(other_point.getX() - x) +
		(other_point.getY() - y)*(other_point.getY() - y) + (other_point.getZ() - z)*(other_point.getZ() - z));
}

std::ostream& Point3D::print(std::ostream& out) const
{
	out << "(" << x << ", " << y << ", " << z << ")";
	return out;
}