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
public:
    GraphicsScene(QObject *parent = Q_NULLPTR);
    void keyPressEvent(QKeyEvent *keyEvent);


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
    void animateMove(Tile* tile, qreal dx, qreal dy);
    Tile* tiles[4][4];
    bool gameover = false;
};

#endif // GRAPHICSSCENE_H
