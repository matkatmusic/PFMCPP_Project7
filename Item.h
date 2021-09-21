#pragma once

#include <string>

struct Character;
struct Item
{
    virtual ~Item() { }
    virtual void use(Character*) = 0;
    Item(const std::string& name_, int effect ) : name(name_), boost(effect) { }
    
    inline const std::string& getName() { return name; }
    inline int getBoost() const { return boost; }
private:
    std::string name;
    int boost;
};