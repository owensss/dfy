#include "../Header/Player.hpp"
#ifdef _DEBUG_
#include <iostream>
#endif

Player::Player(long long _money) : money(_money), dead(false)
{
    states = 0;
#ifdef _DEBUG_
	std::cout << "# Player Create\n";
#endif
}

Player::~Player()
{
#ifdef _DEBUG_
	std::cout << "# Player Destruct\n";
#endif
}

void Player::ReadStream(std::istream& is)
{
    is >> att >> def >> money;
}

// remove money
void Player::Hit(int n)
{
#ifdef _DEBUG_
	std::cout << "# Player::Hit:" << n << ":" << money << std::endl;
#endif
	money -= n;
	// may not be the end of the player though = =b
	if (money < 0) dead = true;
}

// add money
void Player::Heal(int n)
{
#ifdef _DEBUG_
	std::cout << "# Player::Heal:" << n << ":" << money << std::endl;
#endif
	// no overflow checking
	money += n;
}

/*
void Player::AddState(const State& state)
{
	// no error checking
	// c++0x feature
	for (auto& i : states)
		if (i == state)
		{
			// take the bigger one
			i.count = state.count > i.count ? state.count : i.count;
			return;
		}
	states.push_back(state);
	return;
}*/

bool Player::AddToBag(Tools* tool)
{
	if (bag.size() == MAX_BAG_SIZE)
		return false;
	else
		bag.push_back(*tool);
    return true;
}

bool Player::RemoveFromBag(Tools* tool)
{
	for (auto i = bag.begin(); i != bag.end(); ++i)
		if (&(*i) == tool)
		{
			bag.erase(i);
			break;
		}

	return false;
}

//#define _DEBUG_
void Player::Loop() {}

void Player::advance(int i)
{
#ifdef _DEBUG_
    std::cout << "advance" << std::endl;
#endif
    if (x < 0 || y < 0) setVisible(false);
    else setVisible(true);
    setPos(x, y);
}
