#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    game(scene)
{
    ui->setupUi(this);
    ui ->graphicsView ->setScene(&scene);
    setFixedSize(QSize(415, 420));
    connect((ui->nextButton), SIGNAL(clicked()), &game, SLOT(update()));
    connect((ui->clearButton), SIGNAL(clicked()), &game, SLOT(clean()));
}

Widget::~Widget()
{
    delete ui;
}
