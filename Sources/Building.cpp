#include "../Header/Building.hpp"
#ifdef _DEBUG_
#include <iostream>
#endif

Building::Building()
{
	owner = NULL;
#ifdef _DEBUG_
	std::cout << "Building construct\n";
	std::cout << "explicit default constructor!\n";
#endif
}

Building::Building(int _value, bool _can_buy)
	: value(_value), owner(NULL), can_buy(_can_buy)
{
#ifdef _DEBUG_
	std::cout << "Building destruct\n";
#endif
}

Building::~Building()
{
#ifdef _DEBUG_
	std::cout << "Building destruct\n";
#endif
}

// might be changed later
long long Building::Buy(Player * _owner)
{
	if (!can_buy) return 0;
	if (owner != NULL) return 0;
	if (_owner->Money() < (long long)value) return 0;

	_owner->Hit(value);
	owner = _owner;
	return value;
}

// might be changed later
long long Building::Sell(Player * _owner)
{
	if (!owner) return 0;
	if ( owner != _owner) return 0;
	owner->Heal(value);
	// return the building to public
	owner = NULL;
	return value;
}

void Building::ReadStream(std::istream& is)
{
	is >> value >> can_buy;
}
