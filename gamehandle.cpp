#include "gamehandle.h"

GameHandle::GameHandle(QGraphicsScene & setScene, QObject *parent) :
    QObject(parent),
    scene(setScene),
    map1(40, QVector<bool>(40, false)),
    map2(40, QVector<bool>(40, false)),
    items(40, QVector<QGraphicsRectItem * >(40))
{

}
