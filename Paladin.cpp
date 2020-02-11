#include "Paladin.h"
#include "Utility.h"
#include <random>

// Paladin::Paladin
Paladin::Paladin(const std::string& name_, int hp, int armor_)
    : Character(hp, armor_, 10), name(name_)
{
    defensiveItems = makeRandomDefensiveItems();
    helpfulItems = makeRandomHelpfulItems();
}

// Paladin::getName
const std::string& Paladin::getName()
{
    return name;
}

// Paladin::getStats
std::string Paladin::getStats()
{
    return getCharacterStats(this);
}
