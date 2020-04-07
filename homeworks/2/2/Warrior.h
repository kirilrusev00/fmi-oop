#ifndef WARRIOR_H
#define WARRIOR_H

#include "GameCharacter.h"

class Warrior :public GameCharacter
{
public:
	Warrior(const char* = "Warrior");

	friend std::ostream& operator<<(std::ostream&, const Warrior&);
};

#endif