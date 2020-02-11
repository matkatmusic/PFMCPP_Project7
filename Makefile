a.out:
	clang++ -std=c++17 -Weverything -Wno-c++98-compat -Wno-missing-prototypes AttackItem.cpp Character.cpp DefensiveItem.cpp Dragon.cpp DragonSlayer.cpp Dwarf.cpp HelpfulItem.cpp main.cpp Paladin.cpp Utility.cpp && ./a.out

