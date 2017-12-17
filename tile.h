#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <QPainter>

class Tile: public QGraphicsRectItem
{
public:
    Tile(QString text = "", qreal radius = qreal(4));
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void setText(QString text);
    QString getText();

    qreal getRadius() const;
    void setRadius(const qreal &value);
    int mergeTextValue();

private:
    QString text;
    qreal radius;
};

#endif // TILE_H
