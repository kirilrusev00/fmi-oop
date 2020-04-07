#ifndef NPC_H
#define NPC_H

#include "Entity.h"

class NPC :public Entity
{
public:
	NPC();

	const bool isAlive() const override;

	std::ostream& print(std::ostream&) const override;
};

#endif