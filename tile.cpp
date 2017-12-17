#include "tile.h"

#include <iostream>

Tile::Tile(QString text, qreal radius)
{
    this->text = text;
    this->radius = radius;
}

void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    if (painter->pen().color() == Qt::white)
        painter->setPen(QPen(Qt::black));

    switch(this->text.toInt()){
    case 2:
        painter->setBrush(QBrush((Qt::magenta)));
        break;
    case 4:
        painter->setBrush(QBrush((Qt::cyan)));
        break;
    case 8:
        painter->setBrush(QBrush((Qt::green)));
        break;
    case 16:
        painter->setBrush(QBrush((Qt::blue)));
        painter->setPen(QPen((Qt::white)));
        break;
    case 32:
        painter->setBrush(QBrush((Qt::yellow)));
        break;
    case 64:
        painter->setBrush(QBrush((Qt::darkRed)));
        break;
    case 128:
        painter->setBrush(QBrush((Qt::darkGreen)));
        break;
    case 256:
        painter->setBrush(QBrush((Qt::red)));
        break;
    case 512:
        painter->setBrush(QBrush((Qt::darkCyan)));
        break;
    case 1024:
        painter->setBrush(QBrush((Qt::lightGray)));
        break;
    case 2048:
        painter->setBrush(QBrush((Qt::darkMagenta)));
        break;
    default:
        painter->setBrush(QBrush((Qt::black)));
        painter->setPen(QPen((Qt::white)));
    }

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

int Tile::mergeTextValue()
{
    int a = text.toInt();
    a += a;
    this->text = QString("%1").arg(a); //QString::fromStdString(std::to_string(a));
    return a;
}

