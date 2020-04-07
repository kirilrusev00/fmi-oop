#ifndef FIGURE_H
#define FIGURE_H
#include "Point.h"
#include <iostream>
#include <string>

class Figure
{
public:
	//enum to save the type of the figure
	enum shape
	{
		rectangle,
		circle,
		line,
		another
	};

	Figure(shape _type = another);// default constructor
	Figure(shape _type, Point _point, std::string _fill);// constructor with parameters
	Figure(const Figure&);// copy constructor

	Figure& operator=(const Figure&);

	//setters and getters
	void setPoint(const int&, const int&);
	void setXPoint(const int&);
	void setYPoint(const int&);
	void setType(const shape&);
	void setFill(const std::string&);

	const Point getPoint() const;
	const shape getType() const;
	const std::string getFill() const;

	virtual void translate(const int& _x_move, const int& _y_move);// overridden only in class Line

	virtual bool within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const;// overriden in every derived class of Figure
	virtual bool within_circle(const int& x_centre, const int& y_centre, const int& _radius) const;// overriden in every derived class of Figure

	virtual std::ostream& print(std::ostream&) const;// overriden in every derived class of Figure
	//virtual std::istream& input(std::istream&);// overriden in every derived class of Figure

	//friend std::istream& operator>>(std::istream&, Figure*&);
private:
	std::string fill;
protected:
	Point point;
	shape type;
};
//std::istream& operator>>(std::istream&, Figure::shape&);
std::ostream& operator<<(std::ostream&, const Figure::shape&);

std::ostream& operator<<(std::ostream&, const Figure&);


#endif