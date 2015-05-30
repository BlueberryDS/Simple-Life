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

    frameTimer.setInterval(100);

    connect((ui->nextButton), SIGNAL(clicked()), &game, SLOT(update()));
    connect((ui->clearButton), SIGNAL(clicked()), &game, SLOT(clean()));
    connect((ui->pauseButton),SIGNAL(clicked()), this, SLOT(togglePause()));
    connect(&frameTimer, SIGNAL(timeout()), &game, SLOT(update()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::togglePause()
{
    if(ui->pauseButton->text() == "Pause"){
        ui->pauseButton->setText("Play");
        frameTimer.stop();
    }
    else{
        ui->pauseButton->setText("Pause");
        frameTimer.start();
    }
}
