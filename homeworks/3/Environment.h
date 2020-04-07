#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include "NPC.h"
#include "Entity.h"
#include "Player.h"
#include "Mob.h"
#include <vector>

class Environment
{
private:
	std::vector<Entity*> entities;

	Environment();
	Environment(const Environment&);
	const Environment& operator=(const Environment&);
	~Environment();
public:
	static Environment &instance()
	{
		static Environment *instance = new Environment;
		return *instance;
	}
	
	const int getSize() const;

	void add(Entity*);
	Entity& getAt(int index) const;
	void removeAt(int index);
	void generateEntities();
	void destroyEntities();
	Entity* getClosestAliveEntity(const Player&, Entity::type) const;

	friend std::ostream& operator<<(std::ostream&, const Environment&);
};

#endif