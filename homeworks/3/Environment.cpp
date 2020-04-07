#include "Environment.h"

Environment::Environment()
{
}

Environment::Environment(const Environment& rhs)
{
	entities = rhs.entities;
}
const Environment& Environment::operator=(const Environment& rhs)
{
	if (this != &rhs)
	{
		destroyEntities();
		entities = rhs.entities;
	}
	return *this;
}
Environment::~Environment()
{
	destroyEntities();
}

const int Environment::getSize() const
{
	return entities.size();
}

void Environment::add(Entity* _entity)
{
	entities.push_back(_entity);
}
Entity& Environment::getAt(int index) const
{
	return *entities[index];
}
void Environment::removeAt(int index)
{
	entities.erase(entities.begin() + index);
}
//generates 3 mobs, 1 npc and 2 players
void Environment::generateEntities()
{
	Entity* en1 = new Mob(3, 30);
	en1->setName("entity1");
	en1->setLocation(new Point2D(4, 5));
	entities.push_back(en1);

	Entity* en2 = new NPC();
	en2->setName("entity2");
	entities.push_back(en2);

	Entity* en3 = new Player(5, 20);
	en3->setName("entity3");
	en3->setLocation(new Point3D(10, 5, 4));
	entities.push_back(en3);

	Entity* en4 = new Mob(4, 25);
	en4->setName("entity4");
	en4->setLocation(new Point3D(6, 8, 40));
	entities.push_back(en4);

	Entity* en5 = new Player(2, 35);
	en5->setName("entity5");
	en5->setLocation(new Point2D(20, 5));
	entities.push_back(en5);

	Entity* en6 = new Mob(3, 30);
	en6->setName("entity6");
	en6->setLocation(new Point2D(7, 10));
	entities.push_back(en6);
}
void Environment::destroyEntities()
{
	for (int i = 0; i < getSize(); i++)
	{
		delete entities[i];
	}
	entities.clear();
}
Entity* Environment::getClosestAliveEntity(const Player& _player, Entity::type _type) const
{
	double min_size = -1;
	int ind_min_size = -1;
	int i = 0;
	for (i; i < getSize(); i++)
	{
		if (entities[i]->getType() == _type && entities[i]->isAlive() == true)
		{
			min_size = entities[i]->getDistanceTo(_player);
			ind_min_size = i;
			i++;
			break;
		}
	}
	for (i; i < getSize(); i++)
	{
		if (entities[i]->getType() == _type && entities[i]->isAlive() == true)
		{
			double size = entities[i]->getDistanceTo(_player);
			if (size < min_size)
			{
				ind_min_size = i;
				min_size = size;
			}
		}
	}
	return entities[ind_min_size];//Assuming that there are entities of type _type in the vector of entities
}

std::ostream& operator<<(std::ostream& out, const Environment& ent)
{
	for (int i = 0; i < ent.getSize(); i++)
	{
		out << *ent.entities[i];
	}
	return out;
}
