#include "Warrior.h"

Warrior::Warrior(const char* _name):GameCharacter(_name,20,5,4,1)
{
}

std::ostream& operator<<(std::ostream& out, const Warrior& warrior)
{
	out << "Warrior\n";
	operator<<(out, (GameCharacter&)warrior);
	return out;
}