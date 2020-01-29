#include <iostream>
#include <string>
#include <vector>
/*
Project 7: Part 1/1
 video: Chapter 4 Part 2 

Create a branch named Part1

 Inheritance and Composition
 
Build/Run often with this task to make sure you're not breaking the code with each step.
I recommend committing after you get each step working so you can revert to a working version easily if needed.
it's very easy to mess this task up. 

 It's time to get your inner Dungeons & Dragons nerd on!!
 
 1) Make the errors go away.

 2) Assertions have been added with text explaining the things you need to implement.  
        after you implement them, remove the 'assert(false);

 3) add the appropriate #include statements

 4) you're going to need to implement the pure virtual functions in Character-derived classes and Item classes
    
 5) implement the constructors for all the Character-derived types. 
        Dragon's attackDamage is 80
        DragonSlayer's attackDamage is 4
        Dwarf's attackDamage is 4
        Paladin's attackDamage is 10

 6) Each character type gets some Helpful Items and Defensive Items when they're constructed
        Use the functions in Utility.h to give each Character (excluding Dragon, because dragons don't carry items) a RANDOM NUMBER of helpful and defensive items: 
            helpfulItems = makeHelpfulItems(2);
            defensiveItems = makeDefensiveItems(1);
    
 7) create a new Item-derived type that boosts the attack damage called AttackItem 
        add an instance of it to the DragonSlayer class
        make the DragonSlayer::attack use it when the dragonSlayer attacks a dragon. 

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 Send me the the link to your repl.it in a DM on Slack

 Wait for my code review.

 */

#include "Item.h"
#include "Character.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "Dragon.h"
#include "DragonSlayer.h"
//==========================================================
//==========================================================
int main()
{
                      //name, hit points, armor. 
    Dwarf dwarf { "Maldin the Dwarf", 3, 1 };
    Paladin paladin { "Warrick the Paladin", 5, 2 };
    Dragon dragon { "Garry The Dragon", 200, 50 };
    DragonSlayer dragonSlayer { "Virgil the Dragon Slayer", 8, 5 };
    
    std::cout << "\nstart of battle" << std::endl;

    paladin.defend();
    dragon.attack( paladin );
    dwarf.attack( dragon );
    paladin.attack( dragon ); //can't, he's dead
    
    dragonSlayer.help( paladin ); //now he's not dead
    paladin.attack( dragon ); //he's alive now.
    dragon.attack( dwarf ); //dwarf is dead
    paladin.help(dwarf); //dwarf is alive now.
    
    dragon.attack( dragonSlayer ); //he dodges
    dragonSlayer.attack( dragon ); //dragon is slayed.
    //the dragon slayer has no friends and kills everyone 
    dragonSlayer.attack( paladin );
    dragonSlayer.attack( dwarf ); 
    
    std::cout << std::endl << "end of battle stats:" << std::endl;
    
    std::vector<Character*> characters { &dwarf, &paladin, &dragon, &dragonSlayer };
    for( auto* character : characters )
        character->printStats();
    
    return 0;
}