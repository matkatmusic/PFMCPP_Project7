#include <iostream>
#include <string>
#include <vector>
/*
Project 7: Part 1/1
 video: Chapter 4 Part 2 

Create a branch named Part1

Purpose:  This project will teach you how to read existing code someone else has already written, and to get it working again.  Consider this project the "midterm" of the course.

 Inheritance and Composition
 
Build/Run often with this task to make sure you're not breaking the code with each step.
I recommend committing after you get each step working so you can revert to a working version easily if needed.
it's very easy to mess this task up. 

 It's time to get your inner Dungeons & Dragons nerd on!!
 
 1) Make the errors go away.

 2) Assertions have been added with text explaining the things you need to implement.  
        after you implement them, remove the 'assert(false);

 3) add the appropriate #include statements.  Remove any unnecessary #include statements

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
    
 7) Dragon Slayers are allowed 1 special item: an AttackItem 
    create a new Item-derived type that boosts the attack damage called AttackItem 
        add an instance of it to the DragonSlayer class
        make the DragonSlayer::attack use it when the dragonSlayer attacks a dragon. 
        
 8) Clear the warnings as best you can.   
         for the 'vtables' warnings coming from a header file, move any virtual function implementations to the complementary cpp file.
         for 'shadow' warnings, rename the offending variable.
         casting is introduced in the next video and project, so ignore any 'implicit conversion' warnings.

 9) When you compare your output with the expected output, it is fine if the items counts don't match exactly.   It's not important if your DragonSlayer has 5 helpful items, but the expected output shows 3. 

 10) correct any unnecessary keywords related to access specifiers used in the UDTs.

 11) Remember the rules about 'Don't include what you don't use'
    check each source file for things being included that aren't used.
 */

#include "Item.h"
#include "Character.h"
#include "Dwarf.h"
#include "Paladin.h"
#include "Dragon.h"
#include "DragonSlayer.h"
//==========================================================
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */
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

/*
This is the expected output, starting at 'start of battle'
use https://www.diffchecker.com/diff to make sure it is the same.

start of battle
Warrick the Paladin is defending!!
Warrick the Paladin's armor level has been boosted to 5
Garry The Dragon is attacking Warrick the Paladin!!!
Garry The Dragon has attacked Warrick the Paladin
Warrick the Paladin is taking 80 damage!
Warrick the Paladin has died in battle!
Warrick the Paladin's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 10
    is defending: true
    3 helpful items,  7 defensive items

Garry The Dragon defeated Warrick the Paladin and leveled up!
Maldin the Dwarf has attacked Garry The Dragon
Garry The Dragon is taking 4 damage!
Garry The Dragon's stats: 
    hitPoints: 220
    armor: 51
    attack damage: 88
    is defending: false
    0 helpful items,  0 defensive items

Warrick the Paladin can't attack. Warrick the Paladin is dead.
make another party member use an item to revive them

Virgil the Dragon Slayer is going to help Warrick the Paladin
Warrick the Paladin's hit point level has been boosted to 3
Warrick the Paladin has attacked Garry The Dragon
Garry The Dragon is taking 10 damage!
Garry The Dragon's stats: 
    hitPoints: 220
    armor: 41
    attack damage: 88
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is attacking Maldin the Dwarf!!!
Garry The Dragon has attacked Maldin the Dwarf
Maldin the Dwarf is taking 88 damage!
Maldin the Dwarf has died in battle!
Maldin the Dwarf's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 4
    is defending: false
    3 helpful items,  6 defensive items

Garry The Dragon defeated Maldin the Dwarf and leveled up!
Warrick the Paladin is going to help Maldin the Dwarf
Maldin the Dwarf's hit point level has been boosted to 4
Garry The Dragon is attacking Virgil the Dragon Slayer!!!
Virgil the Dragon Slayer is defending!!
Virgil the Dragon Slayer's armor level has been boosted to 9
Virgil the Dragon Slayer is attacking Garry The Dragon !!
Virgil the Dragon Slayer's attack damage level has been boosted to 44
Garry The Dragon is taking 44 damage!
Garry The Dragon's stats: 
    hitPoints: 242
    armor: 16
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is taking 44 damage!
Garry The Dragon's stats: 
    hitPoints: 214
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is taking 44 damage!
Garry The Dragon's stats: 
    hitPoints: 170
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is taking 44 damage!
Garry The Dragon's stats: 
    hitPoints: 126
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is taking 44 damage!
Garry The Dragon's stats: 
    hitPoints: 82
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is taking 44 damage!
Garry The Dragon's stats: 
    hitPoints: 38
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Garry The Dragon is taking 44 damage!
Garry The Dragon has died in battle!
Garry The Dragon's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Virgil the Dragon Slayer has attacked Garry The Dragon
Garry The Dragon is taking 44 damage!
Garry The Dragon has died in battle!
Garry The Dragon's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Virgil the Dragon Slayer defeated Garry The Dragon and leveled up!
Virgil the Dragon Slayer is attacking Warrick the Paladin !!
Virgil the Dragon Slayer has attacked Warrick the Paladin
Warrick the Paladin is taking 48 damage!
Warrick the Paladin has died in battle!
Warrick the Paladin's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 10
    is defending: false
    3 helpful items,  7 defensive items

Virgil the Dragon Slayer defeated Warrick the Paladin and leveled up!
Virgil the Dragon Slayer is attacking Maldin the Dwarf !!
Virgil the Dragon Slayer has attacked Maldin the Dwarf
Maldin the Dwarf is taking 52 damage!
Maldin the Dwarf has died in battle!
Maldin the Dwarf's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 4
    is defending: false
    3 helpful items,  6 defensive items

Virgil the Dragon Slayer defeated Maldin the Dwarf and leveled up!

end of battle stats:
Maldin the Dwarf's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 4
    is defending: false
    3 helpful items,  6 defensive items

Warrick the Paladin's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 10
    is defending: false
    3 helpful items,  7 defensive items

Garry The Dragon's stats: 
    hitPoints: 0
    armor: 0
    attack damage: 96
    is defending: false
    0 helpful items,  0 defensive items

Virgil the Dragon Slayer's stats: 
    hitPoints: 8
    armor: 9
    attack damage: 57
    is defending: false
    4 helpful items,  2 defensive items
*/
