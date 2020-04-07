#include "Figure.h"
/*
std::istream& operator>>(std::istream& in, Figure::shape& set_type)
{
	std::string str;
	in >> str;
	if (str == "rectangle")
	{
		set_type = Figure::rectangle;
	}
	if (str == "circle")
	{
		set_type = Figure::circle;
	}
	if (str == "line")
	{
		set_type = Figure::line;
	}
	if (str != "rectangle" && str != "circle" && str != "line")
	{
		set_type = Figure::another;
	}
	return in;
}*/

std::ostream& operator<<(std::ostream& out, const Figure::shape& get_type)
{
	if (get_type == Figure::rectangle)
	{
		out << "rectangle";
	}
	if (get_type == Figure::circle)
	{
		out << "circle";
	}
	if (get_type == Figure::line)
	{
		out << "line";
	}
	if (get_type == Figure::another)
	{
		out << "another";
	}
	return out;
}

Figure::Figure(shape _type): point(Point()), type(_type)
{
}

Figure::Figure(shape _type, Point _point, std::string _fill): type(_type), point(_point), fill(_fill)
{
}
Figure::Figure(const Figure& rhs) : type(rhs.type), point(rhs.point), fill(rhs.fill)
{
}

Figure& Figure::operator=(const Figure& rhs)
{
	if (this != &rhs)
	{
		setPoint(rhs.point.getX(), rhs.point.getY());
		setType(rhs.type);
		setFill(rhs.fill);
	}
	return *this;
}

void Figure::setPoint(const int& newXPoint, const int& newYPoint)
{
	point.setX(newXPoint);
	point.setY(newYPoint);
}
void Figure::setXPoint(const int& newXPoint)
{
	point.setX(newXPoint);
}
void Figure::setYPoint(const int& newYPoint)
{
	point.setY(newYPoint);
}
void Figure::setType(const shape& newType)
{
	type = newType;
}
void Figure::setFill(const std::string& newFill)
{
	fill = newFill;
}

const Point Figure::getPoint() const
{
	return point;
}
const Figure::shape Figure::getType() const
{
	return type;
}
const std::string Figure::getFill() const
{
	return fill;
}

//translate this->point with vector (_x_move, _y_move)
void Figure::translate(const int& _x_move, const int& _y_move)
{
	int newX = point.getX() + _x_move;
	int newY = point.getY() + _y_move;
	point.setX(newX); 
	point.setY(newY);
}

bool Figure::within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const
{
	return false;
}

bool Figure::within_circle(const int& x_centre, const int& y_centre, const int& _radius) const
{
	return false;
}

std::ostream& Figure::print(std::ostream& out) const
{
	return out;
}
/*
std::istream& Figure::input(std::istream& in)
{
	return in;
}
*/
std::ostream& operator<<(std::ostream& out, const Figure& fig)
{
	return fig.print(out);
}
/*
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
std::istream& operator>>(std::istream& in, Figure*& fig)
{
	Figure::shape set_type;
	in >> set_type;
	if (set_type == Figure::rectangle)
	{
		fig = new Rectangle;
		fig->input(in);
	}
	if (set_type == Figure::circle)
	{
		fig = new Circle;
		fig->input(in);
	}
	if (set_type == Figure::line)
	{
		fig = new Line;
		fig->input(in);
	}
	fig->setFill("\0");

	return in;
}
*/