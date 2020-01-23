#include "Dwarf.h"
#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hp, int armor_) : 
    Character(hp, armor_, 4),
    name(name_)
    {   
        defensiveItems = makeDefensiveItems();
        helpfulItems = makeHelpfulItems();
    }

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}
