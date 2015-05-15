#ifndef GRAPHICSSQUARE_H
#define GRAPHICSSQUARE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QEvent>

class GraphicsSquare : public QGraphicsItem
{
public:
    bool state;
    static bool pressed;

    GraphicsSquare();

    GraphicsSquare(const GraphicsSquare & other);

    QRectF boundingRect() const;

    void paint(QPainter * painter,
                   const QStyleOptionGraphicsItem * option,
                   QWidget * widget);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
};

#endif // GRAPHICSSQUARE_H
