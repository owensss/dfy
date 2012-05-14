#include "../Header/Dice.hpp"
#include <ctime>
#include <cstdlib>

Dice::Dice(void) : times(0)
{
	srand(time(NULL));
	Generate();
    times = 1;
}

void Dice::Generate(void)
{
	value = 0;
	for (int i = 0; i < times; i++)
		value += rand()%MAX_NUM+1;
}

void Dice::SetValue(int _value)
{
    if (_value > Max()) value = Max();
    else if (_value < Min()) value = Min();
    else value = _value;
}
