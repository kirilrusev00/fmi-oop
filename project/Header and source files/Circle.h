#ifndef CIRCLE_H
#define CIRCLE_H
#include "Figure.h"
#include <iostream>

class Circle : public Figure
{
private:
	int radius;
public:
	Circle();//default constructor
	Circle(Point _point, int _radius, std::string _fill);// constructor with parameters
	
	//setter and getter
	void setRadius(const int&);
	
	const int getRadius() const;

	bool within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const override;
	bool within_circle(const int& x_centre, const int& y_centre, const int& _radius) const override;

	std::ostream& print(std::ostream&) const;
	//std::istream& input(std::istream&);
};
#endif