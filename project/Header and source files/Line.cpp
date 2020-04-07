#include "Line.h"

Line::Line() :Figure(line), end(Point())
{
}
Line::Line(Point _point, Point _end, std::string _fill) :
	Figure(line, _point, _fill), end(_end)
{
}

void Line::setEnd(const int& newXEnd, const int& newYEnd)
{
	end.setX(newXEnd);
	end.setY(newYEnd);
}
void Line::setXEnd(const int& newXEnd)
{
	end.setX(newXEnd);
}
void Line::setYEnd(const int& newYEnd)
{
	end.setY(newYEnd);
}

const int Line::getXEnd() const
{
	return end.getX();
}
const int Line::getYEnd() const
{
	return end.getY();
}

//translate this->point and this->end with vector (_x_move, _y_move)
void Line::translate(const int& _x_move, const int& _y_move)
{
	Figure::translate(_x_move, _y_move);
	int new_x_end = getXEnd() + _x_move;
	int new_y_end = getYEnd() + _y_move;
	setEnd(new_x_end, new_y_end);
}

//check if this line is within a rectangle {min_x <= x <= max_x; min_y <= y <= max_y}
bool Line::within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const
{
	return ((point.getX() >= min_x) && (point.getX() <= max_x) && (getXEnd() >= min_x) && (getXEnd() <= max_x)
		&& (point.getY() >= min_y) && (point.getY() <= max_y) && (getYEnd() >= min_y) && (getYEnd() <= max_y));
}

//check if this line is within a circle with centre (x_centre, y_centre) and radius _radius
bool Line::within_circle(const int& x_centre, const int& y_centre, const int& _radius) const
{
	Point centre(x_centre, y_centre);

	return (centre.getDistanceTo(point) <= _radius && centre.getDistanceTo(end) <= _radius);
}

std::ostream& Line::print(std::ostream& out) const
{
	out << getType() << " " << getPoint() << " " << getXEnd() << " " << getYEnd() << " " << getFill() << "\n";
	return out;
}
/*
std::istream& Line::input(std::istream& in)
{
	in >> point;

	int set_x_end, set_y_end;

	in >> set_x_end >> set_y_end;

	setEnd(set_x_end, set_y_end);

	return in;
}
*/