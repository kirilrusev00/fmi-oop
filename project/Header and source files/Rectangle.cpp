#include "Rectangle.h"

Rectangle::Rectangle():Figure(rectangle), width(0),height(0)
{
}
Rectangle::Rectangle(Point _point, int _width, int _height, std::string _fill) :
	Figure(rectangle, _point, _fill), width(_width), height(_height)
{
}

void Rectangle::setWidth(const int& newWidth)
{
	width = newWidth;
}
void Rectangle::setHeight(const int& newHeight)
{
	height = newHeight;
}

const int Rectangle::getWidth() const
{
	return width;
}
const int Rectangle::getHeight() const
{
	return height;
}

//check if this rectangle is within another rectangle {min_x <= x <= max_x; min_y <= y <= max_y}
bool Rectangle::within_rectangle(const int& min_x, const int& min_y, const int& max_x, const int& max_y) const
{
	//the limits for the coordinates of a point (x,y) in this rectangle:
	//x_top_left_rect <= x <= x_bottom_right_rect and y_top_left_rect <= y <= y_bottom_right_rect
	int x_top_left_rect = point.getX();
	int y_top_left_rect = point.getY();
	int x_bottom_right_rect = x_top_left_rect + getWidth();
	int y_bottom_right_rect = y_top_left_rect + getHeight();

	return ((x_top_left_rect >= min_x) && (x_bottom_right_rect <= max_x)
		&& (y_top_left_rect >= min_y) && (y_bottom_right_rect <= max_y));
	
}

//check if this rectangle is within a circle with centre (x_centre, y_centre) and radius _radius
bool Rectangle::within_circle(const int& x_centre, const int& y_centre, const int& _radius) const
{
	Point centre(x_centre, y_centre);

	//the limits for the coordinates of a point (x,y) in this rectangle:
	//x_left_rect <= x <= x_right_rect and y_top_rect <= y <= y_bottom_rect
	int x_left_rect = point.getX();
	int y_top_rect = point.getY();
	int x_right_rect = x_left_rect + getWidth();
	int y_bottom_rect = y_top_rect + getHeight();
	//the vertices of this rectangle:
	Point top_left(x_left_rect, y_top_rect);
	Point top_right(x_right_rect, y_top_rect);
	Point bottom_left(x_left_rect, y_bottom_rect);
	Point bottom_right(x_right_rect, y_bottom_rect);

	return (centre.getDistanceTo(top_left) <= _radius && centre.getDistanceTo(top_right) <= _radius
		&& centre.getDistanceTo(bottom_left) <= _radius && centre.getDistanceTo(bottom_right) <= _radius);
}

std::ostream& Rectangle::print(std::ostream& out) const
{
	out << getType() << " " << getPoint() << " " << getWidth() << " " << getHeight() << " " << getFill() << "\n";
	return out;
}
/*
std::istream& Rectangle::input(std::istream& in)
{
	in >> point;
	
	int set_width, set_height;
	in >> set_width >> set_height;

	setWidth(set_width);
	setHeight(set_height);

	return in;
}
*/