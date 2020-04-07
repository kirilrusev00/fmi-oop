#ifndef LINE_H
#define LINE_H
#include "Figure.h"
#include <iostream>

class Line : public Figure
{
private:
	Point end;
public:
	Line();//default constructor
	Line(Point _point, Point _end, std::string _fill);//constructor with parameters
	
	//setters and getters
	void setEnd(const int&, const int&);
	void setXEnd(const int&);
	void setYEnd(const int&);
	
	const int getXEnd() const;
	const int getYEnd() const;

	void translate(const int& _x_move, const int& _y_move) override;

	bool within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const override;
	bool within_circle(const int& x_centre, const int& y_centre, const int& _radius) const override;

	std::ostream& print(std::ostream&) const;
	//std::istream& input(std::istream&);
};
#endif