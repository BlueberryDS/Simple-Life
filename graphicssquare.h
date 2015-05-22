#ifndef GRAPHICSSQUARE_H
#define GRAPHICSSQUARE_H

#include<QGraphicsItem>
#include<QPainter>
#include<QEvent>

class GraphicsSquare : public QGraphicsItem
{
    bool state;
    static bool pressed;
public:

    GraphicsSquare();

    GraphicsSquare(const GraphicsSquare & other);

    QRectF boundingRect() const;

    void paint(QPainter * painter,
                   const QStyleOptionGraphicsItem * option,
                   QWidget * widget);

    bool getState() {return state;}

    void setState(bool _state);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseDoubleClickEvent(QGraphicsSceneMouseEvent * event);
    virtual void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
};

#endif // GRAPHICSSQUARE_H
