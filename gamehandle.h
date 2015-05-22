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

    QVector<QVector <bool> > map;
    QVector<QVector <GraphicsSquare> > items;

public:
    explicit GameHandle(QGraphicsScene & setScene, QObject *parent = 0);

public slots:
    void update();
    void clean();
};

#endif // GAMEHANDLE_H
