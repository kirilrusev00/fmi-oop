#ifndef POINT_H
#define POINT_H
#include <iostream>

class Point
{
private:
	int x;
	int y;
public:
	Point();//default constructor
	Point(int set_x, int set_y);//constructor with parameters

	//setters and getters
	void setX(const int&);
	void setY(const int&);

	const int getX() const;
	const int getY() const;

	const double getDistanceTo(const Point&) const;//get the distance between two points

	//friend std::istream& operator>>(std::istream&, Point&);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

#endif
