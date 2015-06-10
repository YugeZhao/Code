#include <QApplication>
#include "mainwindow.h"
#include "game.h"
#include "player.h"

Game* game;

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);

    MainWindow w;
    w.show();

    game = new Game();
    game->show();

    return a.exec();
}

