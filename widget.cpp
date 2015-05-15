#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::Widget(QGraphicsScene & scene):Widget(0){
    setFixedSize(QSize(415, 420));
    ui->graphicsView->setScene(&scene);
}

Widget::~Widget()
{
    delete ui;
}
