#include "Player.h"
#include "Mob.h"

Player::Player(int _damage, int _health) : Entity(player), damage(_damage), health(_health)
{
}

Player::Player(type type_of_class, int _damage, int _health) : Entity(type_of_class), damage(_damage), health(_health)
{
}

void Player::setDamage(const int& newDamage)
{
	damage = newDamage;
}
void Player::setHealth(const int& newHealth)
{
	health = newHealth;
}

const int Player::getDamage() const
{
	return damage;
}
const int Player::getHealth() const
{
	return health;
}

const bool Player::isAlive() const
{
	return health > 0;
}
void Player::attack(Player& rhs) const
{
	if (rhs.getType() == mob)
	{
		if (getDistanceTo(rhs) < 5)
		{
			Mob other_player = static_cast<Mob&>(rhs);
			int newHealth = other_player.getHealth();
			if (newHealth < 0)
			{
				newHealth = 0;
			}
			other_player.setHealth(newHealth);
		}
	}
	if (rhs.getType() == player)
	{
		if (getDistanceTo(rhs) < 5)
		{
			int newHealth = rhs.getHealth();
			if (newHealth < 0)
			{
				newHealth = 0;
			}
			rhs.setHealth(newHealth);
		}
	}
}

std::ostream& Player::print(std::ostream& out) const
{
	out << id << " " << type_of_class << " " << name 
		<< "\n Location: " << *location << " " 
		<< "\n Damage: " << damage 
		<< "\n Health: " << health << "\n";
	return out;
}