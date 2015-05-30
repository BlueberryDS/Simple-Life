#ifndef WIDGET_H
#define WIDGET_H

#include "gamehandle.h"
#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT


    QGraphicsScene scene;
    GameHandle game;

public:
    explicit Widget(QWidget *parent = 0);

    ~Widget();
public slots:

    void togglePause();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
