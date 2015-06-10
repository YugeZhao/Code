
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <stdlib.h>
#include "game.h"

extern Game* game;

/* Creates enemies
 */
Enemy::Enemy()
{
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //draw the rect
    setRect(0,0,100,100);

    //connect
    QTimer* timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

/* Move enemies down
 */
void Enemy::move()
{
    //move down
    setPos(x(),y()+5);
    if(pos().y() > 600/*pos().y()+rect().height()<0*/){

        //decrease health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
