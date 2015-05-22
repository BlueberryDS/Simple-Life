#include "graphicssquare.h"
#include <iostream>

bool GraphicsSquare::pressed = false;

GraphicsSquare::GraphicsSquare() : state(false)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

GraphicsSquare::GraphicsSquare(const GraphicsSquare &other) : state(other.state)
{
    setAcceptHoverEvents(true);
    setFlag(QGraphicsItem::ItemIsSelectable);
}

QRectF GraphicsSquare::boundingRect() const
{
    return QRectF(0, 0, 10, 10);
}

void GraphicsSquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF box(0, 0, 10, 10);
    QRectF fill(1, 1, 9, 9);
    QPen boxPen(Qt::black, 1);
    QBrush fillBrush(Qt::blue);

    painter->setPen(boxPen);
    painter->drawRect(box);

    if(state) painter->fillRect(fill, fillBrush);
}

void GraphicsSquare::setState(bool _state)
{
    state = _state;
    update();
}

void GraphicsSquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(pressed)
        pressed = false;
    else
        state = !state;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void GraphicsSquare::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = true;
    update();
}



void GraphicsSquare::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    if(pressed) state = !state;
    update();
    QGraphicsItem::hoverEnterEvent(event);
}
