#include "Dwarf.h"
#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hp_, int armor_) : Character(hp_, armor_, 4), name(name_)
{
	helpfulItems = makeHelpfulItems(1);
    defensiveItems = makeDefensiveItems(2);
}


const std::string& Dwarf::getName()
{
	return name;
}

std::string Dwarf::getStats()
{
	return getCharacterStats(this);
}
