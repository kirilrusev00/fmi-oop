#include "Wizzard.h"

Wizzard::Wizzard(const char* _name):GameCharacter(_name, 30, 30, 2, 2)
{
}

std::ostream& operator<<(std::ostream& out, const Wizzard& wizzard)
{
	out << "Wizzard\n";
	operator<<(out, (GameCharacter&)wizzard);
	return out;
}