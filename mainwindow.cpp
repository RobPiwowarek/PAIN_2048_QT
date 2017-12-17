#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <graphicsscene.h>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new GraphicsScene();

    ui->graphicsView->setScene(scene);

    connect(scene, &GraphicsScene::setScore, ui->scoreLabel, &QLabel::setText);
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::resetGame);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

void MainWindow::resetGame()
{
    scene->resetGame();
}
