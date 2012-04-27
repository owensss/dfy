#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Item.hpp"
#include "Tools.hpp"
#include <istream>
#include <list>
class Item;
class Tools;

#ifndef _ENUM_STATE_
const int s_none = 0;
const int s_trapped = 1;
const int s_posioned = 2;
#endif

static const unsigned INIT_MONEY = 10000;
static const unsigned MAX_BAG_SIZE = 10;

struct State
{
	int type;
	int effect;
	int count;
	bool operator == (const State& rhs) {return type == rhs.type;}
};

// replace HP with ... money???
class Player
{
	public:
		Player(long long _money = INIT_MONEY);
		virtual ~Player();
		virtual void ReadStream(std::istream&);
		// looper
		virtual void Loop(void);
		// remove money from player
		virtual void Hit(int n);
		// add(pick up) money
		virtual void Heal(int n);
		// posioned, godmod(- -b) etc.
		virtual void AddState(const State& state);
		bool Dead(void) const {return dead;}
		long long Money(void) const {return money;}
		unsigned Att(void) {return att;}
		unsigned Def(void) {return def;}
		void SetAtt(int _att) {att = _att;}
		void SetDef(int _def) {def = _def;}
		void AddAtt(int value) {att += value;}
		void SubAtt(int value) {def -= value;}
		void AddDef(int value) {def += value;}
		void SubDef(int value) {def -= value;}
	// bag actions
	public:
		// return sucess?
		virtual bool AddToBag(Tools * item);
		// return sucess?
		virtual bool RemoveFromBag(Tools * item);
		//virtual const std::list<Item*>& listBagItem(void);
	private:
		int att;
		int def;
		long long money;
		std::list<Tools> bag;
		std::list<State> states;
	private:
		bool dead;
};

#endif
