#ifndef _BUILDING_HPP_
#define _BUILDING_HPP_

#include "Item.hpp"
#include "Player.hpp"
#ifndef NULL
#define NULL 0
#endif

class Building : public Item
{
	public:
		Building(int _value, bool _can_buy);
		virtual ~Building();
		/*
		virtual bool CanUpgrade(void);
		// shall have enough money
		virtual bool Upgrade(Player * owner, long long _price);
		*/
		// if cannot buy(that is, has a owner or not in selling), return 0
		virtual void ReadStream(std::istream&);
		bool CanBuy(void) {return can_buy||owner;}
		virtual long long Sell(Player * _owner);
		// return the price, return 0 if cannot buy
		virtual long long Buy(Player * _owner);
		virtual const Player * Owner(void) {return owner;}
		/*
		// price to buy or upgrade
		virtual const long long Price(void) const {return price;}
		*/
		// value of the building. selling price
		virtual long long Value(void) const {return value;}
	private:
		explicit Building(void);
		// unsigned long long price;
		unsigned long long value;
		Player * owner;
		bool can_buy;
		// int level;
};

#endif
