#ifndef _ITEMS_HPP_
#define _ITEMS_HPP_
#include "Object.hpp"
#include <iostream>
#include <QGraphicsPixmapItem>

enum itemtype {tNULL, tRoad, tBlank, tCreature};

class Road;
class Trigger;
class Item;
class Blank;
class Creature;

union ItemType
{
    Road* road;
    Blank* blank;
    Creature* creature;
};

struct MapItem
{
    itemtype type;
    ItemType it;
};

class Item : public QGraphicsPixmapItem
{
	public:
		Item() {};
		virtual ~Item() {};
        void SetX(int _x) { x = _x; }
        void SetY(int _y) { y = _y; }
        int GetX(void) const { return x; }
        int GetY(void) const { return y; }
        virtual void ReadStream(std::istream&) = 0;
        virtual void advance(int phase) {};
    private:
        int x;
        int y;
};

#endif
