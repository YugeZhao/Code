
#include <QFont>
#include <QLabel>
#include "mainwindow.h"
#include "game.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

/* Start easy game
 */
void MainWindow::easy_game_begin() {
    board = new Game(this);
    this->setCentralWidget(board);
}

/* Start Medium game
 */
void MainWindow::medium_game_begin() {
    board = new Game(this);
    this->setCentralWidget(board);
}

/* Start hard game
 */
void MainWindow::hard_game_begin() {
    board = new Game(this);
    this->setCentralWidget(board);
}

/*Game over
 */
void MainWindow::game_over() {

    // Take the current board game out of the central widget of MainWindow
    QWidget* wid = this->centralWidget();
    wid->setParent(NULL);
    // Line above will delete the widget gracefully (no memory errors)

    // Display something which says that you lost, maybe display high score.

    // Reset the MainWindow with the initial startup screen
    ui->setupUi(this);


}




MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    board = new Game(this);
    this->setCentralWidget(board);
}

void MainWindow::on_pushButton_2_clicked()
{
    board = new Game(this);
    this->setCentralWidget(board);
}



void MainWindow::on_pushButton_3_clicked()
{
    board = new Game(this);
    this->setCentralWidget(board);
}


