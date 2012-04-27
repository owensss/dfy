#ifndef _CREATURE_HPP_
#define _CREATURE_HPP_
#include "Item.hpp"
#include "Player.hpp"

class Player;

class Creature : public Item
{
	public:
		Creature();
		~Creature();
		virtual void ReadStream(std::istream& is);
		// if not able to, return false
        bool CanTame(Player * _owner) {return tame;}
        void SetTame(bool can = false) {tame = can;}
		virtual unsigned Att(void) {return att;}
		virtual unsigned Def(void) {return def;}
		void Hurt(unsigned time) {hurt = time;}
		void SetAtt(int _att) {att = _att;}
		void SetDef(int _def) {def = _def;}
		void AddAtt(int value) {att += value;}
		void SubAtt(int value) {def -= value;}
		void AddDef(int value) {def += value;}
		void SubDef(int value) {def -= value;}
	private:
		int att;
		int def;
		Player * owner;
        bool tame;
		// time before recovery. 0 not hurt
		unsigned hurt;
};

#endif
