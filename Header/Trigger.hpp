#ifndef _TRIGGER_HPP
#define _TRIGGER_HPP
#include "Player.hpp"
#include "Item.hpp"
#include "Map.hpp"

class Map;

class Trigger
{
	public:
        explicit Trigger(Map * parent) { map = parent; }
		virtual ~Trigger() {}
        void Setup(Item* _sender, void(*op)(Map*, Item*, Player*),
			   unsigned _count = 0);
        void SetReciever(Player* p) { reciever = p; }
		void Go(void);
		unsigned Count(void) {return count;}
	private:
        // invalid construction
        explicit Trigger() {};
		Item* sender;
		Player* reciever;
        void (*f)(Map*, Item*, Player*);
		unsigned count;
        Map * map;
};

#endif
