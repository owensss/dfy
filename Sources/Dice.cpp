#include "../Header/Dice.hpp"
#include <ctime>
#include <cstdlib>

Dice::Dice(void) : times(0)
{
	srand(time(NULL));
	Generate();
}

void Dice::Generate(void)
{
	value = 0;
	for (int i = 0; i < times; i++)
		value += rand()%MAX_NUM+1;
}

