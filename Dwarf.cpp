#include "Dwarf.h"
#include "Utility.h"

// Dwarf::Dwarf
Dwarf::Dwarf(const std::string& name_, int hp, int armor_)
    : Character(hp, armor_, 4), name(name_)
{
    defensiveItems = makeRandomDefensiveItems();
    helpfulItems = makeRandomHelpfulItems();
}

// Dwarf::getName
const std::string& Dwarf::getName()
{
    return name;
}

// Dwarf::getStats
std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}
