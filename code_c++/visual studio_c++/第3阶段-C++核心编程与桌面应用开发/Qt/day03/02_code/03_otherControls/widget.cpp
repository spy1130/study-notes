#include "widget.h"
#include "ui_widget.h"
#include <QMovie>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    //设置label播放 gif
    QMovie *movie = new QMovie(":/Image/mario.gif",QByteArray(),this);
    ui->label_2->setMovie(movie);
    movie->start();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_pushButton_25_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}
