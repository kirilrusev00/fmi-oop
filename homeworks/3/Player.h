#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player :public Entity
{
protected:
	int damage;
	int health;
public:
	Player(int _damage = 0, int _health = 0);
	Player(type, int _damage = 0, int _health = 0);

	void setDamage(const int&);
	void setHealth(const int&);

	const int getDamage() const;
	const int getHealth() const;

	const bool isAlive() const override;
	void attack(Player&) const;

	std::ostream& print(std::ostream&) const override;
};

#endif