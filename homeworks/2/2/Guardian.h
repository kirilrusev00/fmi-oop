#ifndef GUARDIAN_H
#define GUARDIAN_H

#include "GameCharacter.h"

class Guardian :public GameCharacter
{
public:
	//Guardian();
	Guardian(const char* = "Guardian");

	friend std::ostream& operator<<(std::ostream&, const Guardian&);
};

#endif