#ifndef GAMEHANDLE_H
#define GAMEHANDLE_H

#include <QObject>
#include <QGraphicsScene>
#include <QVector>
#include "graphicssquare.h"


class GameHandle : public QObject
{
    Q_OBJECT

    int xNum;
    int yNum;

    QGraphicsScene & scene;

    QVector<QVector <bool> > map1;
    QVector<QVector <bool> > map2;

    QVector<QVector <GraphicsSquare> > items;

public:
    explicit GameHandle(QGraphicsScene & setScene, QObject *parent = 0);
};

#endif // GAMEHANDLE_H
