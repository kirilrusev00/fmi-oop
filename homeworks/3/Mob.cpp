#include "Mob.h"

Mob::Mob(int _damage, int _health) : Player(mob, _damage, _health)
{
}

void Mob::attack(Mob& rhs) const
{
	if (getDistanceTo(rhs) < 5)
	{
		int newHealth = rhs.getHealth() - this->damage;
		if (newHealth < 0)
		{
			newHealth = 0;
		}
		rhs.setHealth(newHealth);
	}
}