#include "game.h"
#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include "player.h"
#include <QGraphicsView>
#include <QTimer>
#include <QObject>
#include <QBoxLayout>
#include <QPushButton>
#include <QWidget>
#include <QStyle>

/*New game starts
 */
Game::Game(QWidget* parent):QGraphicsView(parent)
{



    //QApplication a(argc, argv);


    //    QString fileName("crab-clip-art-crab-clipart-3-300x226.png");
    //    QString fileName(":/Images/Muncher.jpg");
        QString fileName(":/images/Muncher.png");
        muncher_image = new QPixmap(fileName);

    //scene
    scene = new QGraphicsScene;
    //to put the scene
    player = new Player();
    player->setRect(0,0,100,100);\





    //add item to the scene
    scene->addItem(player);

    //make item focused
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //add a view
    QGraphicsView* view = new QGraphicsView(scene);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2, view->height()-player->rect().height());


    //creat score
    score = new Score();
    scene -> addItem(score);

    //create health
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);




    //Enemy
    QTimer* timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);
    //return a.exec();

    show();
}



