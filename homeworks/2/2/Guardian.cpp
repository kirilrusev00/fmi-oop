#include "Guardian.h"
#include <iostream>

Guardian::Guardian(const char* _name) :GameCharacter(_name, 40, 25, 1, 3)
{
}

std::ostream& operator<<(std::ostream& out, const Guardian& guardian)
{
	out << "Guardian\n";
	operator<<(out,(GameCharacter&) guardian);
	return out;
}