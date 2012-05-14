// test
#define _DEBUG_
#include "../Header/gamewindow.hpp"
#include "../Header/Dice.hpp"
#ifdef _DEBUG_
#include <iostream>
#include <cstdlib>
#include <ctime>
using std::cout;
using std::endl;
#endif

void delay(int msec)
{
    time_t start = clock();
    while ((clock()-start)*1000/CLOCKS_PER_SEC < msec);
}

GameWindow::GameWindow(QWidget * parent) : QMainWindow(parent), scene(this), view(this)
{
#ifdef _DEBUG_
    cout << "gamewindow creating" << endl;
#endif
    // setup pointers
    map = NULL;
    // setup ui;
    QObject::connect(&timer, SIGNAL(timeout()), &scene, SLOT(advance()));
    timer.setInterval(piece);
    scene.setSceneRect(0, 0, 500, 500);

    ui.setupUi(this);
    view.setScene(&scene);
    view.setMinimumSize(500, 500);
    view.setSceneRect(0, 0, 500, 500);
    view.show();
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(IncDiceIndex()));
    QObject::connect(this, SIGNAL(DiceIndChanged()), this, SLOT(PlayerWalk()));
    QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(UpdatePlayerPos()));
    // setup timer
    // connections
    // next clicked, player goes through road
//    QObject::connect(ui.Next, SIGNAL(clicked()), this, SLOT(PlayerGo()));
    // end turn clicked, nefxt enabled for curr player usage
//    QObject::connect(ui.EndTurn, SIGNAL(clicked()), this, SLOT(TurnEnd()));
//    QObject::connect(ui.Next, SIGNAL(clicked()), this, SLOT(TurnBegin()));
}

GameWindow::~GameWindow()
{
}

// arrange space acorrding to map row & col
void GameWindow::SetupMap(Map * _map)
{
    map = _map;
    if (!map) return ;

    // end turn clicked, switch to next player
    QObject::connect(ui.EndTurn, SIGNAL(clicked()), map, SLOT(NextPlayer()));

    // add Item
    for (unsigned i = 0; i < map->Row(); ++i)
    {
        for (unsigned j = 0; j < map->Col(); ++j)
            switch (map->GetItem(i, j).type)
            {
                case tRoad:
                    scene.addItem(map->GetItem(i, j).it.road);
                    break;
                case tBlank:
                    scene.addItem(map->GetItem(i, j).it.blank);
                    break;
                case tCreature:
                    scene.addItem(map->GetItem(i, j).it.creature);
                    break;
                default:
                    break;
            }
    }

    for (unsigned i = 0; i < map->GetPlayerNum(); ++i)
    {
        switch (map->GetPlayer(i)->GetType())
        {
            case t_none:
            default:
              map->GetPlayer(i)->setPixmap(QPixmap("normal_player.gif", "gif"));
              scene.addItem(map->GetPlayer(i));
              QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(AdvancePlayer()));
              break;
        }
    }
    timer.start();
    ReDraw();

#ifdef _DEBUG_
    cout << "setup map finished" << endl;
#endif
}

void GameWindow::DrawItem(int y, int x)
{
#ifdef _DEBUG_
    cout << "drawing item at :" << y << ":" << x << endl;
#endif
    switch (map->GetItem(y, x).type)
    {
        case tRoad:
#ifdef _DEBUG_
        cout << "type = road" << endl;
#endif
            map->GetItem(y, x).it.road->setPos(x*block_w, y*block_h);
            break;
        case tBlank:
            map->GetItem(y, x).it.blank->setPos(x*block_w, y*block_h);
            break;
        case tCreature:
            map->GetItem(y, x).it.creature->setPos(x*block_w, y*block_h);
        default:
            break;
    }
//    pixs[y][x].setPos(x*block_w, y*block_h);
#ifdef _DEBUG_
    cout << "position = " << y*block_h << ":" << x*block_w << endl;
#endif
//    scene.update();
}

void GameWindow::ReDraw(void)
{
    for (unsigned i = 0 ; i < map->Row(); ++i)
        for (unsigned j = 0; j < map->Col(); ++j)
            DrawItem(i, j);
    for (unsigned i = 0 ; i < map->GetPlayerNum(); ++i)
        DrawPlayer(map->GetPlayer(i),
                   map->GetPlayerOnMap(i).road);
}

void GameWindow::DrawPlayer(const Player * p,
     int y, int x)
{
#ifdef _DEBUG_
    cout << "Drawing Player " << p->GetID() << " at " << y << ":" << x << endl;
    cout << p->scenePos().y() << p->scenePos().x()<< endl;
#endif
    p->SetX(x);
    p->SetY(y);
//    scene.advance();
    //scene.update(0, 0, 500, 500);
}

void GameWindow::DrawPlayer(const Player * p, Road * r)
{
    p->SetX(r->GetX()*block_w);
    p->SetY(r->GetY()*block_h);
#ifdef _DEBUG_
    cout << "Player " << p->GetID() << " " << r->GetY()*block_h << ":" << r->GetX()*block_w << endl;
#endif
}

void GameWindow::PlayerGo(int index)
{
#ifdef _DEBUG_
    cout << "Player " << index << " on loop" << endl;
    cout << "curr_player id = " << map->GetCurrentPlayerID() << endl;
#endif
    dice.Generate();
    dice_index = 0;
}

void GameWindow::PlayerWalk(void)
{
    map->CurrPOnMap().road = map->CurrPOnMap().road->Next();
#ifdef _DEBUG_
    cout << map->CurrPOnMap().road->GetX() << map->CurrPOnMap().road->GetY() << endl;
#endif
}

void GameWindow::AdvancePlayer(void)
{

}

void GameWindow::IncDiceIndex(void)
{
#ifdef _DEBUG_INCDICEINDEX_
    cout << "cond : " << map->GetCurrentPlayer()->GetState() << s_walk << "dice_index " << dice_index << endl;
#endif
    if ( !(map->GetCurrentPlayer()->GetState()&s_walk) )
    {
        if (dice_index == dice)
        {
            map->CurrPOnMap().road->PlayerComeIn(map->GetCurrentPlayer());
            dice_index = dice+1;
#ifdef _DEBUG_
            cout << "dice index changed to " << dice_index << ":" << dice << endl;
            cout << "curr_road  = " << map->CurrPOnMap().road->GetY() << map->CurrPOnMap().road->GetX() << endl;
#endif
        }
        else if (dice_index < dice)
        {
            map->CurrPOnMap().road->PlayerByPass(map->GetCurrentPlayer());
            ++dice_index; emit DiceIndChanged();
#ifdef _DEBUG_
            cout << "dice index changed to " << dice_index << ":" << dice << endl;
#endif
        }
        else dice_index = dice+1;
    }
}

void GameWindow::UpdatePlayerPos(void)
{
    bool flag = false;

    // update curr_x
    int curr_x = map->GetCurrentPlayer()->GetX();
    int dest_x = map->CurrPOnMap().road->GetX()*block_w;
    if (curr_x != dest_x)
    {
        flag = true;
        if (curr_x > dest_x)
            if (curr_x-dest_x<=single_step)
                map->GetCurrentPlayer()->SetX(dest_x);
            else
                map->GetCurrentPlayer()->SetX(curr_x-single_step);
        else
            if (dest_x-curr_x<=single_step)
                map->GetCurrentPlayer()->SetX(dest_x);
            else
                map->GetCurrentPlayer()->SetX(curr_x+single_step);
    }

    // update curr_y
    int curr_y = map->GetCurrentPlayer()->GetY();
    int dest_y = map->CurrPOnMap().road->GetY()*block_h;
    if (curr_y != dest_y)
    {
        flag = true;
        if (curr_y > dest_y)
            if (curr_y-dest_y<=single_step)
                map->GetCurrentPlayer()->SetY(dest_y);
            else
                map->GetCurrentPlayer()->SetY(curr_y-single_step);
        else
            if (dest_y-curr_y<=single_step)
                map->GetCurrentPlayer()->SetY(dest_y);
            else
                map->GetCurrentPlayer()->SetY(curr_y+single_step);
    }

#ifdef _DEBUG_UPDATEPLAYER_POS_
    cout << "flag = " << flag << endl;
#endif
    if (flag) map->GetCurrentPlayer()->AddState(s_walk);
    else
    {
        map->GetCurrentPlayer()->RemoveState(s_walk);
    }
}
