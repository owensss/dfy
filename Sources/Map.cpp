#define _DEBUG_
#include "../Header/Map.hpp"
#include <string>
#include <typeinfo>
using namespace std;

Map::Map()
{
    mplayer = NULL;
	player_num = 1;
    map = NULL;
    cur_player = 0;
}

Map::~Map() {}

// this functions shall be written after all other classes are imped
void Map::ReadStream(std::istream& is)
{
#ifdef _DEBUG_
    cout << "entering map::readStream\n";
#endif
	// first Line is x, y
    is >> row >> col;
    map = new MapItem*[row];
	string type;
    // read each items
    for (int i = 0; i < row; ++i)
	{
        map[i] = new MapItem[row];
        for (int j = 0; j < col; ++j)
            ReadItem(is, i, j);
    }
    ReadInitRoad(is);
    ReadRoadRoute(is);
    ReadTrigger(is);
}

// score is the number of shaizi - -b
// poor English shangbuchilition
void Map::PlayerGo(Player * p, unsigned score)
{
	for (MapPlayer * pi = mplayer; pi != mplayer+player_num; ++pi)
	{
		if (pi->player == p)
		{
			for (unsigned i = 0; i < score; ++i)
			{
				pi->road = pi->road->Next();
                pi->road->PlayerByPass(pi->player);
			}
			pi->road->PlayerComeIn(pi->player);
			break;
		} // end if find player
	} // end foreach in mplayer
}

void Map::SetPlayerNum(int num)
{
    // reset player num. shall do release first
	if (num < 0) num = -num;
	player_num = num;

	if (mplayer) delete [] mplayer;
	mplayer = new MapPlayer[player_num];
    for (unsigned i = 0; i < player_num; i++)
	{
		mplayer[i].player = NULL;
		mplayer[i].road = NULL;
	}
}

void Map::AddPlayer(Player * p)
{
    for (unsigned i = 0 ; i < player_num; i++)
	{
        // find fisrt not null player pointer
        // uninitiallized players are garenteed to be null
		if (mplayer[i].player == NULL)
		{
			mplayer[i].player = p;
			mplayer[i].road = init_road;
            mplayer[i].player->SetX(init_road->GetX());
            mplayer[i].player->SetY(init_road->GetY());
            mplayer[i].player->SetID(i);
            break;
#ifdef _DEBUG_ADD_PLAYER_
            cout << "init Player, id: " << mplayer[i].player->GetID() << " at " << i << endl;
#endif
		}
	}
}

// release map
void Map::Clean(void)
{
	// TODO: ADD Clean Code here
	if (map)
	{
        for (int i = 0; i < row; i++)
			delete map[i];
        delete [] map;
	}
	
	if (mplayer)
		delete [] mplayer;
}

void Map::SetCurrentPlayer(Player *p)
{
    for (unsigned i = 0; i < player_num; ++i)
        if (mplayer->player == p)
        {
            cur_player = i;

            break;
        }
}

void Map::ReadItem(istream& is, int y, int x)
{
    string type;
    is >> type;
    // listing types
    if (type == "Road")
    {
#ifdef _DEBUG_READ_ITEM_
        cout << "Reading Road\n" ;
#endif
        map[y][x].type = tRoad;
        map[y][x].it.road = new Road();
        map[y][x].it.road->ReadStream(is);
        map[y][x].it.road->SetX(x);
        map[y][x].it.road->SetY(y);
    }
    if (type == "Blank")
    {
#ifdef _DEBUG_READ_ITEM_
        cout << "Reading Blank\n";
#endif
        map[y][x].type = tBlank;
        map[y][x].it.blank = new Blank();
        map[y][x].it.blank->ReadStream(is);
        map[y][x].it.blank->SetX(x);
        map[y][x].it.blank->SetY(y);
    }
    if (type == "Mushboy")
    {
#ifdef _DEBUG_
        cout << "Reading Mush Boy" << endl;
#endif
        map[y][x].type = tCreature;
        map[y][x].it.creature = new Mushboy();
        map[y][x].it.creature->ReadStream(is);
        map[y][x].it.creature->SetX(x);
        map[y][x].it.creature->SetY(y);
    }
}

void Map::ReadInitRoad(std::istream& is)
{
    // read road route
    // init position
    int x, y;
    is >> y >> x;
    if (map[y][x].type == tRoad)
    {
#ifdef _DEBUG_
        cout << "Creating initRoad" << y << ":" << x << endl;
#endif
        init_road = map[y][x].it.road;
    }
    else
    {
#ifdef _DEBUG_
        cout << "init road position not valid" << endl;
#endif
        // try to find the init road.
        bool found = false;
        int i;
        int j;
        for (i = 0; i < row && !found; ++i)
            for (j = 0; j < col && !found; ++j)
                if (map[i][j].type == tRoad)
                {
                    init_road = map[i][j].it.road;
                    found = true;
                }
        if (!found)
        {
#ifdef _DEBUG_
            cout << "no road found in map. that must not be lligal" << endl;
#endif
            throw ExpNoRoadFound(this);
        }
        cout << "will select the first found road as init_road"
            << "that is " << i << ", " << j << endl;
    }
}

void Map::ReadRoadRoute(std::istream& is)
{
    int y1, x1;
    int y2, x2;
    do
    {
        is >> y1 >> x1;
        is >> y2 >> x2;
#ifdef _DEBUG_
        cout<<"("<<y1<<", "<<x1<<") ("<<y2<<", "<<x2<<")" << endl;
#endif

        if (y1 == -1 || x1 == -1 || y2 == -1 || x2 == -1) break;

        // if is_road
        if ( (map[y1][x1].type == tRoad)
            &&(map[y2][x2].type == tRoad) )

        {
#ifdef _DEBUG_
            cout << "Creating Road Route For (" << y1 << ", " << x1 << ")" << endl;
#endif
            map[y1][x1].it.road->
                    SetNext(map[y2][x2].it.road);
        }
        else
        {
        // maybe shall write to log
#ifdef _DEBUG_
            cout<<"position ("<<y1<<", "<<x1<<") or ("<<y2<<", "<<x2
               << "not a valid position" << endl;
#endif
        }
    // ends with a -1
    } while (y1 != -1 && x1 != -1 && y2 != -1 && x2 != -1);
    // end while read road pos
}

void Map::ReadTrigger(istream& is)
{
    int sx, sy;
    int dx, dy;
    do
    {
        is >> sy >> sx;
        is >> dx >> dy;
        if (sy == -1 || sx == -1 || dx == -1 || dy == -1) return;

        if (map[dy][dx].type != tRoad && map[sy][sx].type == tRoad) return;
        switch (map[sy][sx].type)
        {
            case tNULL:
            case tRoad:
            case tBlank:
                break;
            case tCreature:
                map[dy][dx].it.road->AddTrigger(
                    map[sy][sx].it.creature->RegTrigger
                            (this, map[dy][dx].it.road)
                );
        }
    } while (1);
}
