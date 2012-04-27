#include "../Header/Road.hpp"
#include <typeinfo>
#ifdef _DEBUG_
#include <iostream>
#endif

Road::Road() : next(NULL)
{
}

Road::~Road() {}

void Road::AddTrigger(Trigger tr)
{
    trigger.push_back(tr);
}

void Road::AddRelateBuilding(Item* item)
{
	// can not add an item twice
	for (auto i : relBuilding)
		if (i == item) return;
	relBuilding.push_back(item);
}

void Road::RemoveRelateBuilding(Item* item)
{
	/*relBuilding.remove_if()
	for (auto& i : relBuilding)
	{

	}*/
	for (auto i = relBuilding.begin(); i != relBuilding.end(); ++i)
		if ((*i) == item)
		{
			relBuilding.erase(i);
			break;
		}
}

void Road::SetNext(Road* road)
{
	next = road;
}

void Road::PlayerComeIn(Player * p)
{
	for (auto i=trigger.begin(); i !=trigger.end(); ++i)
	{
		i->SetReciever(p);
		i->Go();
		if (i->Count() == 0)
		{
			trigger.erase(i);
		}
	}
}

void Road::ReadStream(std::istream& is)
{
}
