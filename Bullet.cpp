#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QList>
#include "enemy.h"
#include "game.h"

extern Game* game;

/* Draw bullets
 */
Bullet::Bullet()
{
    //draw the rect
    setRect(0,0,10,50);

    //connect
    QTimer* timer = new QTimer();

    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

/* Move bullets up
 */
void Bullet::move()
{
    //collision
    QList<QGraphicsItem*> colliding_items = collidingItems();
    int n = colliding_items.size();

    foreach(QGraphicsItem* i, colliding_items){
        Enemy* item = dynamic_cast<Enemy*> (i);
        if(item){
            //incream the score
            game->score->increase();

            scene()->removeItem(item);

            delete item;
            return;
        }
    }

    /*for(int i = 0; i<n; ++i){
        if( typeid((*colliding_items(i))) == typeid(Enemy)){
            //remove both
            scene()->removeItem(colliding_items(i));
            scene()->removeItem(this);

            delete colliding_items(i);
            delete this;
            return;
        }
    }*/


    //move up
    setPos(x(),y()-10);
    if(pos().y()+rect().height()<0){
        scene()->removeItem(this);
        delete this;
    }
}
