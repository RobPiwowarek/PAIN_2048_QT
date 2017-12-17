#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <graphicsscene.h>
#include <settingsdialog.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void resizeEvent(QResizeEvent * event);

public slots:
    void resetGame();
    void displaySettings();
    void changeSettings();

private:
    Ui::MainWindow *ui;
    SettingsDialog *settings;
    GraphicsScene *scene;
};

#endif // MAINWINDOW_H
