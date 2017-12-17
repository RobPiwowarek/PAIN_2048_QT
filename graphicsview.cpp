#include "graphicsview.h"

GraphicsView::GraphicsView(QWidget *parent): QGraphicsView(parent)
{

}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    fitInView(this->scene()->sceneRect(), Qt::KeepAspectRatio);
}
