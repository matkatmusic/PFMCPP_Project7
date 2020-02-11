#include "DefensiveItem.h"
#include "Utility.h"

void DefensiveItem::use(Character* character)
{
    useDefensiveItem(character, *this);
}
