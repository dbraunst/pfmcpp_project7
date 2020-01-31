#include "DefensiveItem.h"
#include "Utility.h"
#include "Character.h"


void DefensiveItem::use(Character* character)
{
    //assert(false); 
    //make your defensive item use the appropriate Utility helper functions
    std::cout << character->getName() << " uses his Defensive Item!\n";
    useDefensiveItem(character, *this);
}
