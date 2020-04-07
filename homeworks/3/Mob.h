#ifndef MOB_H
#define MOB_H

#include "Player.h"

//Player inherits Mob because it has the same methods and data members
class Mob :public Player
{
public:
	Mob(int _damage = 0, int _health = 0);

	void attack(Mob&) const;
};

#endif