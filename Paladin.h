#pragma once
#include "Character.h"

struct Paladin : Character
{
    Paladin(std::string name_, int hp_, int armor_);
    std::string getStats() override;
    const std::string& getName() override;
private:
    const std::string name;
};
