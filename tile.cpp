#include "tile.h"

#include <iostream>

Tile::Tile(QString text, qreal radius)
{
    this->text = text;
    this->radius = radius;
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    if (this->text == "2")
        painter->setBrush(QBrush((Qt::magenta)));

    if (this->text == "4")
        painter->setBrush(QBrush((Qt::cyan)));

    painter->drawRoundedRect(this->rect(), this->radius, this->radius);
    painter->drawText(-this->boundingRect().width()/1.75, -this->boundingRect().height()/2, this->text);
}

void Tile::setText(QString text)
{
    this->text = text;
}

QString Tile::getText()
{
    return this->text;
}

qreal Tile::getRadius() const
{
    return radius;
}

void Tile::setRadius(const qreal &value)
{
    radius = value;
}

void Tile::squareTextValue()
{
    int a = text.toInt();
    a += a;
    this->text = QString("%1").arg(a); //QString::fromStdString(std::to_string(a));
}

