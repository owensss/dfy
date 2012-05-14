#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "Item.hpp"
#include "Player.hpp"
#include "Road.hpp"
#include "Blank.hpp"
#include "Mushboy.hpp"
#include <istream>
#include <exception>
#include <QObject>
#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
using std::cout;
using std::endl;
#endif

struct MapPlayer
{
	Road * road;
	Player* player;
};

class Map : public QObject
{
    Q_OBJECT

	public:
		Map();
		~Map();
		// this will be a big work to do
		// assign
		void ReadStream(std::istream&);
        unsigned Row(void) const {return row;}
        unsigned Col(void) const {return col;}
        const MapItem& GetItem(unsigned y, unsigned x) const {return map[y][x];}
        MapItem& GetItem(unsigned y, unsigned x) {return map[y][x];}
		// forwardPlayer Some Blocks
		// check triggers
    public slots:
        void PlayerGo(Player * p, unsigned score);
		void AddPlayer(Player * p);
		void SetPlayerNum(int num);
        void SetCurrentPlayer(Player * p);
        void SetCurrentPlayer(int index) { cur_player = index; }
        unsigned GetCurrentPlayerID(void) { return cur_player; }
        MapPlayer& CurrPOnMap(void) { return mplayer[cur_player]; }
        Player * GetCurrentPlayer(void) {return mplayer[cur_player].player; }

        void NextPlayer(void)
            { (++cur_player==player_num) ? cur_player=0:cur_player;}
        unsigned GetPlayerNum(void) const { return player_num; }
        Player* GetPlayer(unsigned index)
            {cout << index << mplayer[index].player->GetID() << endl; return mplayer[index].player; }
        MapPlayer& GetPlayerOnMap(unsigned index)
            { return mplayer[index]; }
		// reset map
        void Clean(void);
    signals:
        void MapChanged(int y, int x);
	private:
        MapItem** map;
        unsigned cur_player;
        MapPlayer* mplayer;
		unsigned player_num;
        int row;
        int col;
	private:
        Road * init_road;
    private:
        void ReadItem(std::istream&, int y, int x);
        void ReadInitRoad(std::istream&);
        void ReadRoadRoute(std::istream&);
        void ReadTrigger(std::istream&);
};

class ExpNoRoadFound : public std::exception
{
public:
    explicit ExpNoRoadFound(Map * _map) : map(_map) {}
    virtual const char* what()
    {
        return "no road found on the map\n";
    }
private:
    const Map * map;
};

#endif
