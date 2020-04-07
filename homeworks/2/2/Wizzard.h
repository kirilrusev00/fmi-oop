#ifndef WIZZARD_H
#define WIZZARD_H

#include "GameCharacter.h"

class Wizzard :public GameCharacter
{
public:
	Wizzard(const char* = "Wizzard");

	friend std::ostream& operator<<(std::ostream&, const Wizzard&);
};

#endif