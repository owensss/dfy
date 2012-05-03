#define _DEBUG_
#include "../Header/Building.hpp"
#include "../Header/Item.hpp"
#include "../Header/Player.hpp"
#include "../Header/Trigger.hpp"
#include "../Header/Events.hpp"
#include "../Header/Creature.hpp"
#include "../Header/Map.hpp"
#include "../Header/Road.hpp"
#include "../Header/Tools.hpp"
#include "../Header/Blank.hpp"
#include "../Header/Dice.hpp"
#include <fstream>

using namespace std;

#ifdef _DEBUG_
void test(Item*, Player*);
#endif

// Gloabal Vars
Map map;
Player * players;
unsigned player_num;

// End of Gloabal Vars

void ReadPlayerNum(void);
void CreateMap(void);
void CreatePlayer(void);
bool Win(void);

int main()
{
try
{
	ReadPlayerNum();
	CreatePlayer();
	CreateMap();
    while (Win() == false)
    {
        for (unsigned i = 0; i < player_num; ++i)
		{
			Dice dice;
			// how many steps to go
			dice.Generate();
			// while ! GUI End Turn pressed
			/*
			while (! )
			{
				// TODO: players can use tools here
			}
			*/
			map.PlayerGo(players+i, dice);
        }
    }

    return 0;
}
catch (const char* err)
{
    cerr << err;
}
}

void ReadPlayerNum(void)
{
    player_num = 0;
}

void CreatePlayer(void)
{
#ifdef _DEBUG_
    cout << "Reading Player.data\n";
#endif
	fstream fs("players.data", fstream::in);
	if (!fs.is_open()) throw "unable to open players.data!\n";
	// TODO: ReadPlayer num here
	// TODO: Add Player Choose func here
    for (unsigned i = 0 ; i < player_num; ++i)
	{
		players[i].ReadStream(fs);
	}
}
void CreateMap(void)
{
	fstream fs("map.data", fstream::in);
	if (!fs.is_open()) throw "unable to open map.data!\n";
	// Readin Player initial pos
	// Items
	// etc
#ifdef _DEBUG_
    cout << "Reading Map\n";
#endif
    map.ReadStream(fs);
    for (unsigned i = 0; i < player_num; ++i)
	{
#ifdef _DEBUG_
        cout << "Reading Player\n";
#endif
		map.AddPlayer(players+i);
	}
}

bool Win(void)
{
	int stands = 0;
    for (unsigned i = 0; i < player_num; ++i)
	{
		if ( !(players+i)->Dead() ) ++stands;
		if (stands > 1) return false;
	}
	return true;
}
