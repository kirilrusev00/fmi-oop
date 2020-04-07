#include "Group.h"

Group::Group()
{

}

Group::Group(const Group& rhs)
{
	shapes = rhs.shapes;
}
Group& Group::operator=(const Group& rhs)
{
	if (this != &rhs)
	{
		destroyShapes();
		shapes = rhs.shapes;
	}
	return *this;
}

const int Group::size() const
{
	return shapes.size();
}

void Group::push_back(Figure* newValue)
{
	shapes.push_back(newValue);
}

//remove an element from the vector on position pos if it exists
bool Group::remove(const int& pos)
{
	if (pos >= 0 && pos < size())
	{
		shapes.erase(shapes.begin() + pos);
		return true;//there is shapes[pos] in the vector
	}
	return false;//there is no shapes[pos] in the vector
}

//pop an element back from the vector if it is not empty
bool Group::pop_back()
{
	if (size() != 0)
	{
		shapes.pop_back();
		return true;//the stack is not empty
	}
	else
	{
		return false;//the stack is empty
	}
}

Figure* Group::operator[](const int& pos) const
{
	return shapes[pos];
}

//check if the figures in this->shape is within a rectangle and return the number of the figures within
int Group::within_rect(const Rectangle& fig) const
{
	int num_figures_within = 0;
	Point _point = fig.getPoint();
	//the limits for the coordinates of a point (x,y) in fig:
	//x_top_left_rect <= x <= x_bottom_right_rect and y_top_left_rect <= y <= y_bottom_right_rect
	int min_x = _point.getX();
	int min_y = _point.getY();
	int max_x = min_x + fig.getWidth();
	int max_y = min_y + fig.getHeight();

	for (int i = 0; i < size(); i++)
	{
		if (shapes[i]->within_rectangle(min_x, min_y, max_x, max_y))
		{
			std::cout << i + 1 << ". " << *shapes[i];
			num_figures_within++;
		}
	}
	return num_figures_within;
}

//check if the figures in this->shape is within a circle and return the number of the figures within
int Group::within_circ(const Circle& fig) const
{
	int num_figures_within = 0;
	for (int i = 0; i < size(); i++)
	{
		Point _point = fig.getPoint();
		if (shapes[i]->within_circle(_point.getX(), _point.getY(), fig.getRadius()))
		{
			std::cout << i + 1 << ". " << *shapes[i];
			num_figures_within++;
		}
	}
	return num_figures_within;
}

//check if the figures in this->shape is within a circle or a rectangle
//and return the number of the figures within
int Group::within(const Figure& fig) const
{
	if (fig.getType() == Figure::rectangle)
	{
		return within_rect(static_cast<Rectangle&>(const_cast<Figure&>(fig)));
	}
	else if (fig.getType() == Figure::circle)
	{
		return within_circ(static_cast<Circle&>(const_cast<Figure&>(fig)));
	}
	else
	{
		return -1;
	}
}

void Group::destroyShapes()
{
	for (int i = 0; i < size(); i++)
	{
		delete shapes[i];
	}
	shapes.clear();
}
Group::~Group()
{
	destroyShapes();
}

std::ostream& operator<< (std::ostream& out, const Group& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		out << i + 1 << ". " << *v.shapes[i];
	}
	return out;
}