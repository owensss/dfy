#ifndef GAMEWINDOW_HPP
#define GAMEWINDOW_HPP
#include "../ui_gamewindow.h"
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "Map.hpp"
#include <QTimer>
#include "Dice.hpp"

class GameWindow : public QMainWindow
{
Q_OBJECT

public:
    GameWindow(QWidget * parent = NULL);
    void SetupMap(Map * _map);
    ~GameWindow();
signals:
    void DiceIndChanged();
public slots:
    void DrawItem(int y, int x);
    void ReDraw(void);
    void PlayerWalk(void);
    //void PlayerWalk(const Player* p, const Road* begin, const Road* end);
    void DrawPlayer(const Player * p, int y, int x);
    void DrawPlayer(const Player * p, Road * r);
    void PlayerGo(int index = -1);
    void TurnBegin() { ui.Next->setDisabled(true); }
    void TurnEnd() { ui.Next->setEnabled(true); }
    void on_Next_clicked(void) {PlayerGo(); TurnBegin();}
    void on_EndTurn_clicked(void) { TurnEnd();}
    void AdvancePlayer();
    void IncDiceIndex();
    void UpdatePlayerPos();
private:
    Ui::GameWindow ui;
    QGraphicsScene scene;
    QGraphicsView view;
    Map * map;
    QTimer timer;
    Dice dice;
    unsigned dice_index;
private:
    // width and height of a single block
    static const int block_w = 70;
    static const int block_h = 70;
    // one piece of time
    static const int piece = 10;
    // step width of player while moving a piece of time
    static const int single_step = 5;
};

#endif // GAMEWINDOW_HPP
