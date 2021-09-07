#include "Dwarf.h"

Dwarf::Dwarf(std::string name_, int hp_, int armor_) : Character(hp_, armor_, 4), name(name_){}


const std::string& Dwarf::getName()
{
	return name;
}

std::string Dwarf::getStats()
{
	
}
