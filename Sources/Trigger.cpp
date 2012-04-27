#include "../Header/Trigger.hpp"

void Trigger::Setup(Item* _sender, Player* _reciever,
				void (*op)(Item*, Player*), unsigned _count)
{
	sender = _sender;
	reciever = _reciever;
	f = op;
	count = _count;
}

void Trigger::Go(void)
{
	f(sender, reciever);
}
