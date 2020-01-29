#include "Utility.h"

#include "HelpfulItem.h"
#include "DefensiveItem.h"
#include "Character.h"
#include <assert.h>
#include "AttackItem.h"
#include <stdlib.h>

/* .   Tried to forward declare but because UseItem functions call functions from the classes I think it has to be done via include*/

//^^ the above was my previous comment to you but then I realized I wasn't forward declaring WITH the inheritance. :) 

std::vector<std::unique_ptr<Item>> makeHelpfulItems()
{
    int num = rand() % 3;

    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<HelpfulItem>(new HelpfulItem()) );
    }
    
    std::cout << "made " << items.size() << " helpful items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeDefensiveItems()
{
    int num = rand() % 3;

    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<DefensiveItem>(new DefensiveItem()) );
    }
    
    std::cout << "made " << items.size() << " defensive items" << std::endl;
    return items;
}

std::vector<std::unique_ptr<Item>> makeAttackItems()
{
    int num = rand() % 3;
    
    std::vector<std::unique_ptr<Item>> items;
    
    while( num-- >= 0 )
    {
        items.push_back( std::unique_ptr<AttackItem>(new AttackItem()) );
    }
    
    std::cout << "made " << items.size() << " attack items" << std::endl;
    return items;
}

std::string getCharacterStats(Character* ch)
{
    std::string str;
    
    str += "    hitPoints: " + std::to_string(ch->getHP()) + "\n";
    str += "    armor: " + std::to_string(ch->getArmorLevel()) + "\n";
    str += "    attack damage: " + std::to_string(ch->getAttackDamage()) + "\n";
    str += "    is defending: " + std::string((ch->getIsDefending() ? "true" : "false" )) + "\n";
    str += "    " + std::to_string(ch->getHelpfulItems().size()) + " helpful items,  " + std::to_string(ch->getDefensiveItems().size()) + " defensive items";

    return str;
}

void useDefensiveItem(Character* character, Item& item)
{
    //dwarves, paladins, and DragonSlayers get extra boosts from defensive item.
    if( auto* ch = dynamic_cast<Dwarf*>(character) )
    {
        ch->boostArmor( item.getBoost() * 1.1 );
        std::cout << ch->getName() << " had their armor boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<Paladin*>(character) )
    {
        //same with paladins
        ch->boostArmor( item.getBoost() * 1.3 );
        std::cout << ch->getName() << " had their armor boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<DragonSlayer*>(character))
    {
        ch->boostArmor( item.getBoost() * 1.5 );
        std::cout << ch->getName() << " had their armor boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't need defensive items
    }  
}
void useHelpfulItem(Character* character, Item* item)
{
    if( auto* ch = dynamic_cast<Dwarf*>(character) )
    {
        ch->boostHitPoints(item->getBoost() * 2);
        std::cout << ch->getName() << " had their hitpoints boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<Paladin*>(character) )
    {
        ch->boostHitPoints(item->getBoost() * 1.5);
        std::cout << ch->getName() << " had their hitpoints boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<DragonSlayer*>(character))
    {
        ch->boostHitPoints(item->getBoost() * 1.25);
        std::cout << ch->getName() << " had their hitpoints boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't carry helpful items!
    }
}
void useAttackItem(Character* character, Item* item)
{
    if( auto* ch = dynamic_cast<Dwarf*>(character) )
    {
        ch->boostAttackDamage(item->getBoost() * 1.5);
        std::cout << ch->getName() << " had their attack boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<Paladin*>(character) )
    {
        ch->boostAttackDamage(item->getBoost() * 1.33);
        std::cout << ch->getName() << " had their attack boosted" << std::endl;
    }
    else if( auto* ch = dynamic_cast<DragonSlayer*>(character))
    {
        //assert(false);
        ch->boostAttackDamage(ch->getAttackDamage() * 10);
        std::cout << ch->getName() << " had their attack boosted" << std::endl;
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        //so their attack item should boost their attack damage by a factor of 10
        //this means you need to GET the attack damage, multiply it by the item's boost, and BOOST the attackDamage with that multiplied value.  
        //check Character.h for available member functions you can use.
    }
    else if( auto* ch = dynamic_cast<Dragon*>(character) )
    {
        //dragons don't carry attack items!
    }
}
