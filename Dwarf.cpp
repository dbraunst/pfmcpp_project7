#include "Dwarf.h"
#include "Utility.h"

Dwarf::Dwarf(std::string name_, int hp, int armor_) : 
    Character(hp, armor_, 4),
    name(name_)
    {   
        defensiveItems = makeDefensiveItems(rand() % 3);
        helpfulItems = makeHelpfulItems(rand() % 3);
    }

const std::string& Dwarf::getName()
{
    return name;
}

std::string Dwarf::getStats()
{
    return getCharacterStats(this);
}
