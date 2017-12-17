#include "graphicsscene.h"
#include <iostream>

GraphicsScene::GraphicsScene(QObject *parent){
    int i = 0, j = 0;

    for (i = 0; i < 4; ++i){
        for (j = 0; j < 4; ++j){
            QGraphicsRectItem *rect = new QGraphicsRectItem();
            rect->setRect(-50.0, -50.0, 90, 90);
            rect->setPos(-50.0 + 100 * j, -50.0 + 100 * i);

            this->tiles[i][j] = Q_NULLPTR;
            this->addItem(rect);
        }
    }

    Tile *firstTile = new Tile("2", 10);
    Tile *secondTile = new Tile("4", 10);

    firstTile->setRect(-50.0, -50.0, 50, 50);
    firstTile->setPos(170.0, -30.0);

    secondTile->setRect(-50.0, -50.0, 50, 50);
    secondTile->setPos(270.0, 70.0);

    tiles[0][2] = firstTile;
    tiles[1][3] = secondTile;

    this->addItem(firstTile);
    this->addItem(secondTile);
}

void GraphicsScene::keyPressEvent(QKeyEvent *keyEvent){
    if (gameover) return;

    if (animation) return;

    switch(keyEvent->key()){
            case Qt::Key_Up:
                up();
                break;
            case Qt::Key_Left:
                left();
                break;
            case Qt::Key_Right:
                right();
                break;
            case Qt::Key_Down:
                down();
                break;
    }
}

void GraphicsScene::unlockKeyHandlers()
{
    animation = false;

    foreach (Tile* tile, tilesToDelete) {
        if (tile != Q_NULLPTR)
            this->removeItem(tile);
    }

    tilesToDelete.clear();
}

void GraphicsScene::resetGame()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j){
            if (tiles[i][j] != Q_NULLPTR){
                this->removeItem(tiles[i][j]);
                delete tiles[i][j];
            }
        }

    this->score = 0;
    emit setScore(QString("%1").arg(this->score));

    gameover = false;
    animation = false;

    Tile *firstTile = new Tile("2", 10);
    Tile *secondTile = new Tile("4", 10);

    firstTile->setRect(-50.0, -50.0, 50, 50);
    firstTile->setPos(170.0, -30.0);

    secondTile->setRect(-50.0, -50.0, 50, 50);
    secondTile->setPos(270.0, 70.0);

    tiles[0][2] = firstTile;
    tiles[1][3] = secondTile;

    this->addItem(firstTile);
    this->addItem(secondTile);
}

void GraphicsScene::up(){
    bool shouldSpawn = false;

    QTimeLine *timer = new QTimeLine(250);

    animation = true;

    connect(timer, &QTimeLine::finished, this, &GraphicsScene::unlockKeyHandlers);

    for (int i = 1; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            if (tiles[i][j] != Q_NULLPTR){
                int k;

                for (k = 1; k < i; ++k){
                    if (tiles[i-k][j] != Q_NULLPTR)
                        break;
                }

                if (tiles[i-k][j] != Q_NULLPTR){
                    if (tiles[i][j]->getText() == tiles[i-k][j]->getText()){
                        animateMove(tiles[i][j], 0.0, -100.0*k, timer);

                        score += tiles[i-k][j]->mergeTextValue();

                        emit setScore( QString("%1").arg(this->score));

                        tiles[i-k][j]->update(tiles[i-k][j]->boundingRect());

                        tilesToDelete.append(tiles[i][j]);

                        tiles[i][j] = Q_NULLPTR;

                        shouldSpawn = true;

                    }
                    else{
                            animateMove(tiles[i][j], 0.0, -100.0*(k-1), timer);

                            tiles[i-k+1][j] = tiles[i][j];

                            if (k > 1)
                                tiles[i][j] = Q_NULLPTR;

                            shouldSpawn = true;
                    }
                }
                else{
                    animateMove(tiles[i][j], 0.0, -100.0*k, timer);

                    tiles[i-k][j] = tiles[i][j];

                    tiles[i][j] = Q_NULLPTR;

                    shouldSpawn = true;
                }
            }
        }
    }

    timer->start();

    if(shouldSpawn){
        spawnNewTileAtBottom();
    }
}

void GraphicsScene::down(){

}

void GraphicsScene::left(){

}

void GraphicsScene::right(){

}

void GraphicsScene::spawnNewTileAtBottom(){
    Tile *newTile = new Tile("2", 10);

    int y = 3;
    int x = 0;

    x = qrand() % 4;

    if (tiles[y][x] != Q_NULLPTR){
        x = 0;

        while(x < 4){
            std::cout << x << std::endl;

            if (tiles[y][x] == Q_NULLPTR){
                break;
            }

        ++x;
        }
    }

    if (x == 4) return;

    tiles[y][x] = newTile;

    newTile->setRect(-50.0, -50.0, 50, 50);

    newTile->setPos(-30.0 + 100*x, 270);

    this->addItem(newTile);
}

void GraphicsScene::spawnNewTileAtRight()
{

}

void GraphicsScene::spawnNewTileAtLeft()
{

}

void GraphicsScene::spawnNewTileAtTop()
{

}

void GraphicsScene::isOver()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            if (tiles[i][j] == Q_NULLPTR)
                gameover = true;
}

void GraphicsScene::animateMove(Tile *tile, qreal dx, qreal dy, QTimeLine *timer)
{
    QGraphicsItemAnimation *animation = new QGraphicsItemAnimation;

    std::cout << dx << " " << dy << std::endl;
    animation->setItem(tile);
    animation->setTimeLine(timer);
    animation->setPosAt(1, QPointF(tile->x() + dx, tile->y() + dy));
}
