#pragma once
#include "Character.h"

struct Dragon : Character
{
	Dragon(std::string name_, int hp_, int armor);
    void attack(Character& other) override;
	std::string getStats() override;
	const std::string& getName() override;
private:
    const std::string name;
};

