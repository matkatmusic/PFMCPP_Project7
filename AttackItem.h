#pragma once

#include "Item.h"

struct AttackItem : Item
{
    AttackItem() : Item("attack item", 2) {}
    void use(Character* character) override;
};
