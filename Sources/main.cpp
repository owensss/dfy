#define _DEBUG_
#include <fstream>
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
#include "../Header/gamewindow.hpp"
#include "../Header/playercreator.hpp"
#include <QApplication>

using std::cout;
using std::fstream;
using std::cerr;

#ifdef _DEBUG_
void test(Item*, Player*);
#endif

// Gloabal Vars
Map map;
Player** players = NULL;
unsigned player_num;

// End of Gloabal Vars

void ReadPlayerNum(const PlayerCreator&);
void CreateMap(void);
void CreatePlayer(const PlayerCreator&);
bool Win(void);
void DestroyPlayer(void);

int main(int argc, char* argv[])
{
try
{
    QApplication app(argc, argv);
	GameWindow gw;
	PlayerCreator pc;
	while (! pc.CheckValid()) pc.exec();
	ReadPlayerNum(pc);
	CreatePlayer(pc);
	CreateMap();
    gw.SetupMap(&map);
    gw.show();
/*
*/
    return app.exec();
}
catch (const char* err)
{
    cerr << err;
    return -1;
}
}

void ReadPlayerNum(const PlayerCreator& pc)
{
    player_num = pc.Player_num();
	players = new Player*[player_num];
}

void CreatePlayer(const PlayerCreator& pc)
{
	std::string names[3];
	unsigned prof[3];
#ifdef _DEBUG_
    cout << "Reading Player.data\n";
#endif
	pc.NameProf(names, prof);
	fstream fs("players.data", fstream::in);
	if (!fs.is_open()) throw "unable to open players.data!\n";
	// TODO: ReadPlayer num here
	// TODO: Add Player Choose func here
    for (unsigned i = 0 ; i < player_num; ++i)
	{
		switch (prof[i])
		{
			default:
				players[i] = new Player();
				players[i]->SetName(names[i]);
                players[i]->SetType();
				break;
		}
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
	map.SetPlayerNum(player_num);
    for (unsigned i = 0; i < player_num; ++i)
	{
#ifdef _DEBUG_
        cout << "Reading Player\n";
#endif
		map.AddPlayer(players[i]);
	}
}

bool Win(void)
{
	int stands = 0;
    for (unsigned i = 0; i < player_num; ++i)
	{
		if ( !(players[i])->Dead() ) ++stands;
		if (stands > 1) return false;
	}
	return true;
}
