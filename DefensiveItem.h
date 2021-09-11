#pragma once

#include "Item.h"

struct DefensiveItem : Item
{
    DefensiveItem() : Item("defensive item", 3) { }
    void use(Character* character) override;
};

