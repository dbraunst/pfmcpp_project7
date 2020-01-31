#include "Paladin.h"
#include "Utility.h"

// Paladin::Paladin
Paladin::Paladin(std::string name_, int hp, int armor_) :
    Character(hp, armor_, 10),
    name(name_)
    {
        defensiveItems = makeDefensiveItems(rand() % 3);
        helpfulItems = makeHelpfulItems(rand() % 3);

    }

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return getCharacterStats(this);
}
