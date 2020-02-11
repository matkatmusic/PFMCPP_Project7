#include "DragonSlayer.h"
#include "Dragon.h"
#include "AttackItem.h"
#include "Utility.h"

// DragonSlayer::DragonSlayer
DragonSlayer::DragonSlayer(const std::string& name_, int hp, int armor_)
    : Character(hp, armor_, 4), name(name_)
{
    defensiveItems = makeRandomDefensiveItems();
    helpfulItems = makeRandomHelpfulItems();
    attackItem = std::make_unique<AttackItem>();
}

// DragonSlayer::getName
const std::string& DragonSlayer::getName()
{
    return name;
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!"
              << std::endl;
    if (auto* dragon = dynamic_cast<Dragon*>(&other))
    {
        // DragonSlayers get a 10x boost when attacking dragons, from their
        // attack item. so they should USE their attack item before attacking
        // the dragon...
        //
        if (attackItem)
        {
            attackItem->use(this);
            attackItem.reset();
        }

        while (dragon->getHP() > 0)
        {
            dragon->takeDamage(attackDamage);
        }
    }

    Character::attack(other);
}

// DragonSlayer::getStats
std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}
