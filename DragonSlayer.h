#pragma once

#include "Character.h"

struct DragonSlayer : Character
{
  public:
    DragonSlayer(const std::string& name, int hp, int armor_);

    const std::string& getName() override;
    std::string getStats() override;
    void attack(Character& other) override;

  private:
    const std::string name;
    std::unique_ptr<Item> attackItem;
};
