#include "DragonSlayer.h"
#include "Dragon.h"
#include <assert.h> 
#include "Utility.h"
#include "AttackItem.h"

DragonSlayer::DragonSlayer(std::string name_, int hp, int armor_) : 
    Character(hp, armor_, 4),
    name(name_)
    {
        defensiveItems = makeDefensiveItems(rand() % 3);
        helpfulItems = makeHelpfulItems(rand() % 3);
    }

const std::string& DragonSlayer::getName()
{
    return name;
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        
        //assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so they should USE their attack item before attacking the dragon... 
        attackItem.use(this);

        while( dragon->getHP() > 0 )
        {
          dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}

std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}
