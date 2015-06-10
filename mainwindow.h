#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "game.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void easy_game_begin();
    void medium_game_begin();
    void hard_game_begin();

    void game_over();

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();



private:
    Ui::MainWindow *ui;
    Game* board;
};

#endif // MAINWINDOW_H
