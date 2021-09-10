#include "Item.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 10) { }
    void use(Character* character) override;
};
