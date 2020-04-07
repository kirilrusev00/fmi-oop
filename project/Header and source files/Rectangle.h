#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Figure.h"
#include <iostream>

class Rectangle : public Figure
{
private:
	int width;
	int height;
	
public:
	Rectangle();
	Rectangle(Point _point, int _width, int _height, std::string _fill);
	
	//setters and getters
	void setWidth(const int&);
	void setHeight(const int&);

	const int getWidth() const;
	const int getHeight() const;

	bool within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const override;
	bool within_circle(const int& x_centre, const int& y_centre, const int& _radius) const override;

	std::ostream& print(std::ostream&) const;
	//std::istream& input(std::istream&);
};
#endif