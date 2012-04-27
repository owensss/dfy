#ifndef _TRIGGER_HPP
#define _TRIGGER_HPP
#include "Player.hpp"
#include "Item.hpp"

class Trigger
{
	public:
		Trigger() {}
		virtual ~Trigger() {}
		void Setup(Item* _sender, Player* _reciever,
			   		void(*op)(Item*, Player*), unsigned _count = 0);
		void SetReciever(Player* p) {reciever = p;}
		void Go(void);
		unsigned Count(void) {return count;}
	private:
		Item* sender;
		Player* reciever;
		void (*f)(Item*, Player*);
		unsigned count;
};

#endif
