#include "../Header/Creature.hpp"
#ifndef NULL
#define NULL 0
#endif

Creature::Creature()
{
    owner = NULL;
    tame = false;
}

Creature::~Creature()
{
    owner = NULL;
}

void Creature::ReadStream(std::istream& is)
{
//    is >> att >> def >> tame;
}

