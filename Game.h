#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QLabel>
#include <QPixmap>
#include <QString>
#include "player.h"
#include "score.h"
#include "health.h"

class Game:public QGraphicsView
{
public:
    Game(QWidget* parent = 0);


    QGraphicsScene* scene;
    Player* player;
    Score* score;
    Health* health;

    QWidget* Top;


    const QPixmap* muncher_image;
    QPixmap* ogre_image;

};

#endif // GAME_H
