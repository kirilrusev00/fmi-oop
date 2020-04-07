#ifndef POINT2D_H
#define POINT2D_H
#include <string>
#include <iostream>

class Point2D
{
protected:
	double x;
	double y;
public:
	Point2D();
	Point2D(double, double);
	
	void setX(const double&);
	void setY(const double&);

	const double getX() const;
	const double getY() const;
	virtual const std::string getPointType() const;

	double getDistanceTo(const Point2D&) const;

	virtual std::ostream& print(std::ostream&) const;
};

std::ostream& operator<<(std::ostream&, const Point2D&);

#endif