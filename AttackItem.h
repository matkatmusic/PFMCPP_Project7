#include "Item.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 3) { }
    void use(Character* character) override;
};
