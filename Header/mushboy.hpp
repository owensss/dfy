#ifndef _MUSHBOY_HPP_
#define _MUSHBOY_HPP_
#include "Creature.hpp"

class Mushboy : public Creature
{
public:
	Mushboy(void);
    ~Mushboy(void) {};
	void advance(int phase);
    Trigger RegTrigger(Map* map, Road* road);
	void ReadStream(std::istream&);
};

#endif
