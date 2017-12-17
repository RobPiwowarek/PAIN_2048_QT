#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QResizeEvent>

class GraphicsView: public QGraphicsView
{
public:
    GraphicsView(QWidget *parent);
    void resizeEvent(QResizeEvent * event);

};

#endif // GRAPHICSVIEW_H
