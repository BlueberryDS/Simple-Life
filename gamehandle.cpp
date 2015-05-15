#include "gamehandle.h"

GameHandle::GameHandle(QGraphicsScene & setScene, QObject *parent) :
    QObject(parent),
    scene(setScene),
    xNum(35),
    yNum(35),
    map1(xNum, QVector<bool>(yNum, false)),
    map2(xNum, QVector<bool>(yNum, false)),
    items(40, QVector<GraphicsSquare>(40))
{
    for(int i = 0; i < xNum; i++){
        for(int j = 0; j < yNum; j++){
            items[i][j].setPos(10.0 * i, 10.0 * j);
            scene.addItem(&items[i][j]);
        }
    }
}
