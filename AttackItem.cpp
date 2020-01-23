#include "Utility.h"
#include "AttackItem.h"
#include "Character.h"


void AttackItem::use(Character* character)
{
    std::cout << character->getName() << " uses his Attack Item!\n";
    useAttackItem(character, this);
}
