#ifndef _ROAD_HPP_
#define _ROAD_HPP_

#include "Item.hpp"
#include "Events.hpp"
#include "Trigger.hpp"
#include "Player.hpp"
#include <list>

class Road : public Item
{
	public:
		Road();
		~Road();
		// shall maintain trigger road it self
		// preserve a copy of that trigger
		// may be changed later
        void AddTrigger(Trigger tr);
        // useless = =b
		// no player leave function
		// do not maintain the player pointer
		// for later use
		void PlayerComeIn(Player * p);
        void PlayerByPass(Player * p);
		void AddRelateBuilding(Item* _item);
		void RemoveRelateBuilding(Item* item);
        void SetNext(Road* road);
        void SetX (int _x) { x = _x; }
        void SetY (int _y) { y = _y; }
        int GetX(void) const { return x; }
        int GetY(void) const { return y; }
        Road * Next(void) {return next;}
        void ReadStream(std::istream&);
	private:
		Road* next;
		// related building are buildings related with this road
		// so that player here can communicate with these buildings
		std::list<Item*> relBuilding;
		std::list<Trigger> trigger;
        std::list<Trigger> bypassTrigger;
        int x;
        int y;
};

#endif
