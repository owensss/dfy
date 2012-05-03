#ifndef _MAP_HPP_
#define _MAP_HPP_

#include "Item.hpp"
#include "Player.hpp"
#include "Road.hpp"
#include <istream>

struct MapPlayer
{
	Road * road;
	Player* player;
};

class Map
{
	public:
		Map();
		~Map();
		// this will be a big work to do
		// assign
		void ReadStream(std::istream&);
		// forwardPlayer Some Blocks
		// check triggers
		void PlayerGo(Player * p, unsigned score);
		void AddPlayer(Player * p);
		void SetPlayerNum(int num);
		// reset map
        void Clean(void);
	private:
        Item*** map;
        MapPlayer* mplayer;
		unsigned player_num;
        int row;
        int col;
	private:
        Road * init_road;
};

#endif
