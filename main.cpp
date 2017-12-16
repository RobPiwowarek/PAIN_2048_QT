#include "mainwindow.h"
#include <QApplication>
#include <graphicsscene.h>
#include <QGraphicsView>
#include <tile.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return a.exec();
}
