#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include "Item.hpp"
#include "Tools.hpp"
#include <istream>
#include <string>
#include <list>
#include <QGraphicsPixmapItem>
class Item;
class Tools;


#ifndef _ENUM_STATE_
const int s_none = 0;
const int s_trapped = 1;
const int s_posioned = 2;
const int s_walk = 4;
#endif


#ifndef _ENUM_PLAYER_TYPE
const int t_none = 0;
const int t_mage = 1;
const int t_warrior = 2;
const int t_thief = 4;
#endif

static const unsigned INIT_MONEY = 10000;
static const unsigned MAX_BAG_SIZE = 10;

//enum State{s_none = 0, s_trapped = 1, s_posioned = 2, s_stop = 4, s_walk = 8};

// replace HP with ... money???
class Player : public QGraphicsPixmapItem
{
    public slots:
        // overloaded virtual function
        virtual void advance(int i);
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
        void AddState(unsigned state) { states |= state; }
        void RemoveState(unsigned state) { states ^= (states&state); }
        unsigned GetState(void) const {return states; }
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
		void SetName(std::string _name) {name = _name;}
        void SetID(unsigned _id) { id = _id; }
        void SetX(int _x) const { x = _x; }
        void SetY(int _y) const { y = _y; }
        int GetX(void) const { return x; }
        int GetY(void) const { return y; }
        unsigned GetID(void) const { return id; }
        void SetType(unsigned _type = 0) { type = _type; }
        unsigned GetType(void) const { return type; }
	// bag actions
	public:
		// return sucess?
		virtual bool AddToBag(Tools * item);
		// return sucess?
		virtual bool RemoveFromBag(Tools * item);
		//virtual const std::list<Item*>& listBagItem(void);
	private:
		std::string name;
		int att;
		int def;
		long long money;
		std::list<Tools> bag;
        unsigned states;
	private:
		bool dead;
        unsigned id;
        unsigned type;
        mutable int x, y;
};

#endif
