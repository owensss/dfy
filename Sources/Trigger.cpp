#include "../Header/Trigger.hpp"

void Trigger::Setup(Item* _sender,
                void (*op)(Map*, Item*, Player*), unsigned _count)
{
	sender = _sender;
	f = op;
	count = _count;
}

void Trigger::Go(void)
{
    f(map, sender, reciever);
}
