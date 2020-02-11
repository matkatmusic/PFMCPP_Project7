#include "Utility.h"
#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "Character.h"
#include "Dwarf.h"
#include "Dragon.h"
#include "DragonSlayer.h"
#include "Paladin.h"

#include <random>

const int MIN_RANDOM_ITEM = 1;
const int MAX_RANDOM_ITEM = 5;

std::vector<std::unique_ptr<Item>> makeHelpfulItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;

    while (num-- > 0)
    {
        items.push_back(std::unique_ptr<HelpfulItem>(new HelpfulItem()));
    }

    std::cout << "made " << items.size() << " helpful items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeDefensiveItems(int num)
{
    std::vector<std::unique_ptr<Item>> items;

    while (num-- > 0)
    {
        items.push_back(std::unique_ptr<DefensiveItem>(new DefensiveItem()));
    }

    std::cout << "made " << items.size() << " defensive items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeRandomHelpfulItems()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(MIN_RANDOM_ITEM, MAX_RANDOM_ITEM);

    return makeHelpfulItems(dist(gen));
}

std::vector<std::unique_ptr<Item>> makeRandomDefensiveItems()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(MIN_RANDOM_ITEM, MAX_RANDOM_ITEM);

    return makeDefensiveItems(dist(gen));
}

std::string getCharacterStats(Character* ch)
{
    std::string str;

    str += "    hitPoints: " + std::to_string(ch->getHP()) + "\n";
    str += "    armor: " + std::to_string(ch->getArmorLevel()) + "\n";
    str += "    attack damage: " + std::to_string(ch->getAttackDamage()) + "\n";
    str += "    is defending: " +
           std::string((ch->getIsDefending() ? "true" : "false")) + "\n";
    str += "    " + std::to_string(ch->getHelpfulItems().size()) +
           " helpful items,  " +
           std::to_string(ch->getDefensiveItems().size()) + " defensive items";
    return str;
}

void useDefensiveItem(Character* character, Item& item)
{
    // dwarves, paladins, and DragonSlayers get extra boosts from defensive
    // item.
    if (auto* ch = dynamic_cast<Dwarf*>(character))
    {
        ch->boostArmor(static_cast<int>(item.getBoost() * 1.1));
    }
    else if (auto* ch = dynamic_cast<Paladin*>(character))
    {
        // same with paladins
        ch->boostArmor(static_cast<int>(item.getBoost() * 1.3));
    }
    else if (auto* ch = dynamic_cast<DragonSlayer*>(character))
    {
        ch->boostArmor(static_cast<int>(item.getBoost() * 1.5));
    }
    else if (auto* ch = dynamic_cast<Dragon*>(character))
    {
        // dragons don't need defensive items
    }
}
void useHelpfulItem(Character* character, Item* item)
{
    if (auto* ch = dynamic_cast<Dwarf*>(character))
    {
        ch->boostHitPoints(static_cast<int>(item->getBoost() * 2));
    }
    else if (auto* ch = dynamic_cast<Paladin*>(character))
    {
        ch->boostHitPoints(static_cast<int>(item->getBoost() * 1.5));
    }
    else if (auto* ch = dynamic_cast<DragonSlayer*>(character))
    {
        ch->boostHitPoints(static_cast<int>(item->getBoost() * 1.25));
    }
    else if (auto* ch = dynamic_cast<Dragon*>(character))
    {
        // dragons don't carry helpful items!
    }
}
void useAttackItem(Character* character, Item* item)
{
    if (auto* ch = dynamic_cast<Dwarf*>(character))
    {
        ch->boostAttackDamage(static_cast<int>(item->getBoost() * 1.5));
    }
    else if (auto* ch = dynamic_cast<Paladin*>(character))
    {
        ch->boostAttackDamage(static_cast<int>(item->getBoost() * 1.33));
    }
    else if (auto* ch = dynamic_cast<DragonSlayer*>(character))
    {
        // DragonSlayers get a 10x boost when attacking dragons, from their
        // attack item. so their attack item should boost their attack damage by
        // a factor of 10 this means you need to GET the attack damage, multiply
        // it by the item's boost, and BOOST the attackDamage with that
        // multiplied value. check Character.h for available member functions
        // you can use.
        auto atkDamage = ch->getAttackDamage();
        ch->boostAttackDamage(
            static_cast<int>(atkDamage * item->getBoost() * 10));
    }
    else if (auto* ch = dynamic_cast<Dragon*>(character))
    {
        // dragons don't carry attack items!
    }
}
