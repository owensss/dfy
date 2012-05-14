#include "..\Header\mushboy.hpp"
#include "..\Header\Trigger.hpp"

class Map;
class Item;
class Player;
void combat(Map * map, Item* item, Player * p);

using std::istream;

Mushboy::Mushboy()
{
    setPixmap(QPixmap("mushboy.gif", "gif"));
    SetAtt(3);
    SetDef(3);
    SetTame(false);
}

void Mushboy::ReadStream(std::istream& is)
{
    Creature::ReadStream(is);
}

void Mushboy::advance(int phase)
{
}

Trigger Mushboy::RegTrigger(Map* map, Road *road)
{
    Trigger t(map);
    t.Setup(this, combat, (unsigned)(-1));

    return t;
}
