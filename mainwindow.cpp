#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <graphicsscene.h>
#include <QtGui>
#include <iostream>
#include <graphicsview.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    GraphicsView *view = new GraphicsView(this);

    scene = new GraphicsScene();

    QVBoxLayout* vl = ui->verticalLayout;

    view->setScene(scene);

    vl->addWidget(view);

    settings = new SettingsDialog(this);

    connect(scene, &GraphicsScene::setScore, ui->scoreLabel, &QLabel::setText);
    connect(ui->newGameButton, &QPushButton::clicked, this, &MainWindow::resetGame);
    connect(ui->settingsButton, &QPushButton::clicked, this, &MainWindow::displaySettings);
    connect(settings, &SettingsDialog::changeSettings, this, &MainWindow::changeSettings);
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

void MainWindow::displaySettings()
{
    settings->show();
}

void MainWindow::changeSettings()
{
    scene->changeSpawnMode();
}
