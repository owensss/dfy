#include "../Header/Player.hpp"
#include "../Header/Item.hpp"

#define _DEBUG_
#ifdef _DEBUG_
#include <iostream>
void test(Item* sender, Player* reciever)
{
	std::cout << "Item connected with Player\n";
}
#endif
