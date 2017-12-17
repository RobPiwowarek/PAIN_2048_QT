#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <graphicsscene.h>
#include <QtGui>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new GraphicsScene();

    ui->graphicsView->setScene(scene);

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
    ui->graphicsView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
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
