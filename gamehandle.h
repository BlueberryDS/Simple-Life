#ifndef GAMEHANDLE_H
#define GAMEHANDLE_H

#include <QObject>
#include <QGraphicsScene>
#include <QVector>


class GameHandle : public QObject
{
    Q_OBJECT

    QGraphicsScene & scene;

    QVector<QVector <bool> > map1;
    QVector<QVector <bool> > map2;

    QVector<QVector <QGraphicsRectItem *> > items;

public:
    explicit GameHandle(QGraphicsScene & setScene, QObject *parent = 0);

signals:

public slots:
    void resize();
};

#endif // GAMEHANDLE_H
