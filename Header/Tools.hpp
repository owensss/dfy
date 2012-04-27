#ifndef _TOOLS_HPP
#define _TOOLS_HPP
#include "Player.hpp"
#include "Item.hpp"

class Player;
class Item;

class Tools
{
	public:
		Tools(void);
		virtual ~Tools(void);
		virtual void ReadStream(std::istream&);
		// equip, set, drink? anywhat.
		virtual void Use(Player * target) {};
		virtual void Use(Item* target) {};
		void SetOwner(Player * p) { owner = p;}
		void SetPrice(unsigned _price) {price = _price;}
		virtual long long Price(void) {return price;}
		virtual Player * Owner(void) {return owner;}
	private:
		Player * owner;
		unsigned price;
};

#endif
