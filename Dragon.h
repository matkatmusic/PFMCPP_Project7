#pragma once

#include "Character.h"

struct Dragon : Character
{
    void attack(Character& other) override;
private:
    const std::string name;
};

