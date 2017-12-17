#ifndef GRAPHICSSCENE_H
#define GRAPHICSSCENE_H

#include <QGraphicsScene>
#include <tile.h>
#include <QKeyEvent>
#include <QGraphicsItemAnimation>
#include <QTimeLine>
#include <QVector>

class GraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    GraphicsScene(QObject *parent = Q_NULLPTR);
    void keyPressEvent(QKeyEvent *keyEvent);
    void resetGame();

signals:
    void setScore(const QString &);

private slots:
    void unlockKeyHandlers();

private:
    void up();
    void down();
    void left();
    void right();
    void spawnNewTileAtBottom();
    void spawnNewTileAtRight();
    void spawnNewTileAtLeft();
    void spawnNewTileAtTop();
    void isOver();
    void animateMove(Tile* tile, qreal dx, qreal dy, QTimeLine *timer);
    Tile* tiles[4][4];
    QVector<Tile*> tilesToDelete;
    bool gameover = false;
    bool animation = false;
    int score = 0;
};

#endif // GRAPHICSSCENE_H
