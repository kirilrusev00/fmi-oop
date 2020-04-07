#ifndef POINT3D_H
#define POINT3D_H
#include "Point2D.h"

class Point3D : public Point2D
{
protected:
	double z;
public:
	Point3D();
	Point3D(double, double, double);

	void setZ(const double&);

	const double getZ() const;
	const std::string getPointType() const override;

	double getDistanceTo(const Point3D&) const;

	std::ostream& print(std::ostream&) const override;
};

#endif