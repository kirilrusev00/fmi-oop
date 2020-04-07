#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
#include "NPC.h"
#include "Mob.h"
#include "Player.h"
#include "Environment.h"
#include <iostream>
#include <string>

void test(Mob& attacking_player, Entity::type type_attacked_entities)
{
	Environment* env = &Environment::instance();
	env->generateEntities();
	std::cout << *env << "\n";

	//2 vectors that save the indices of mobs in the environment from the closest to the furthest
	std::vector<int> index_attacked_entities;
	//and the distance from them to "attacking_player"
	std::vector<double> distance_to_attacked_entities;

	//add the first mob to the vectors
	int temp = 0;
	for (temp; temp < env->getSize(); temp++)
	{
		if (env->getAt(temp).getType() == Entity::mob)
		{
			index_attacked_entities.push_back(temp);
			double distance = attacking_player.getDistanceTo(env->getAt(temp));
			distance_to_attacked_entities.push_back(distance);
			temp++;
			break;
		}
	}

	//add the other mobs to the vectors
	for (temp; temp < env->getSize(); temp++)
	{
		if (env->getAt(temp).getType() == Entity::mob)
		{
			double distance = attacking_player.getDistanceTo(env->getAt(temp));
			bool is_added = false;
			//check if the current mob is closer to "attacking_player" than other mob in the vectors
			for (int i = 0; i < index_attacked_entities.size(); i++)
			{
				//if it is, insert the current mob in the vectors
				if (distance < distance_to_attacked_entities[i])
				{
					index_attacked_entities.insert(index_attacked_entities.begin() + i, temp);
					distance_to_attacked_entities.insert(distance_to_attacked_entities.begin() + i, distance);
					is_added = true;
					break;
				}
			}
			//if it is not, push it back in the end
			if (is_added == false)
			{
				index_attacked_entities.push_back(temp);
				distance_to_attacked_entities.push_back(distance);
			}
		}
	}

	int num = index_attacked_entities.size();
	//move to and attack all mobs from the closest to the furthest
	for (int i = 0; i < num; i++)
	{
		attacking_player.moveTo(env->getAt(index_attacked_entities[i]));
		attacking_player.attack(static_cast<Mob&>(env->getAt(index_attacked_entities[i])));
		std::cout << env->getAt(index_attacked_entities[i]) << "\n";
		std::cout << attacking_player << "\n";
	}
}

int main()
{
	Mob pl(6, 10);
	std::cout << *pl.getLocation();
	pl.setName("Player1");
	pl.setLocation(new Point3D(3, 4, 5));
	std::cout << *pl.getLocation() << std::endl;

	test(pl, Entity::mob);

	system("pause");
	return 0;
}