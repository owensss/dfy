#include "../Header/Player.hpp"
#include "../Header/Item.hpp"
#include <QMessageBox>
#include "../Header/Map.hpp"
#include "../Header/Creature.hpp"

void blank_road(Map * map, Item* item, Player* p)
{
;
}

void combat(Map * map, Item* item, Player * p)
{
    cout << "combat!" << endl;
    QMessageBox::warning(0, "warning", "Player and item combat!", QMessageBox::Ok);
}
