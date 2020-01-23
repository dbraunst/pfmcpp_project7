#include "DefensiveItem.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "DragonSlayer.h"
#include "Dragon.h"
#include <assert.h> 
#include "Utility.h"
#include "AttackItem.h"

void AttackItem::use(Character* character)
{
    std::cout << "The Dragonslayer Uses his Attack Item!\n";
    useAttackItem(character, this);
}
