#include "NPC.h"

NPC::NPC():Entity(npc)
{
}

const bool NPC::isAlive() const
{
	return true;
}

std::ostream& NPC::print(std::ostream& out) const
{
	out << id << " " << type_of_class << " " << name << " " 
		<< "\n Location: " << *location << "\n";
	return out;
}