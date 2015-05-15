#include "widget.h"
#include <gamehandle.h>
#include <QApplication>
#include <QGraphicsScene>
#include <QVector>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGraphicsScene scene;

    GameHandle game(scene);

    Widget w(scene);
    w.show();



    return a.exec();
}
