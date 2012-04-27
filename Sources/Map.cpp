#include "../Header/Map.hpp"
#include <string>
#include <typeinfo>
using namespace std;

Map::Map()
{
	mplayer = NULL;
	player_num = 1;
	map = NULL;
}

Map::~Map() {}

// this functions shall be written after all other classes are imped
void Map::ReadStream(std::istream& is)
{
	// first Line is x, y
    is >> col >> row;
    map = new Item**[col];
	string type;
    for (int i = 0; i < col; ++i)
	{
        map[i] = new Item*[col];
        for (int j = 0; j < row; ++j)
		{
			cin >> type;
			// listing types
			if (type == "Road")
                map[i][j] = new Road();
			// ReadStream
            map[i][j]->ReadStream(is);
		}
    }

    // read road route
    // init position
    int x1, y1;
    int x2, y2;
    is >> y1 >> x1;
    if (typeid(map[y1][x1]) == typeid(Road*))
    {
        init_road = dynamic_cast<Road*> (map[y1][x1]);
    }
    else
        throw "not a valid init road position;\n";
    do
    {
        is >> x1 >> y1;
        is >> y2 >> x2;
        // if is_road
        if (typeid(map[y1][x1]) != typeid(Road*)
          ||typeid(map[y2][x2]) != typeid(Road*))
        {
            // maybe shall write to log
#ifdef _DEBUG_
            cout<<"position ("<<y1<<", "<<x1<<") or ("<<y2<<", "<<x2
               << "not a valid position\n";
#endif
        }
        else
        {
            dynamic_cast<Road*>(map[y1][x1])->
                    SetNext(dynamic_cast<Road*>(map[y2][x2]));
        }
    // ends with a -1
    } while (y1 != -1 || x1 != -1 || x2 != -1 || y2 != -1);
    // end while read road pos
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
		}
	}
}

// release map
void Map::Clean(void)
{
	// TODO: ADD Clean Code here
	if (map)
	{
        for (int i = 0; i < col; i++)
		{
            for (int j = 0; j < row; j++)
                delete map[i][j];
            delete [] map[i];
		}
        delete [] map;
	}
	
	delete [] mplayer;
}
