#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QTimer>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget),
    mTimerId(0),
    mTimerId2(0)
{
    ui->setupUi(this);
    //创建定时器
//    startTimer(1000);
}

void Widget::timerEvent(QTimerEvent *event)
{
    if(event->timerId()==this->mTimerId)
    {
        static int num = 1;
        //qDebug()<<num++;
        this->ui->lcdNumber->display(num++);
    }

    if(event->timerId()==this->mTimerId2)
    {
        static int num2 = 1;
        this->ui->lcdNumber_2->display(num2++);
    }
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_start_clicked()
{
    //定时器1，1秒响一次
    this->mTimerId = startTimer(1000);
}

void Widget::on_pushButton_stop_clicked()
{
    //停止计时器
    killTimer(this->mTimerId);
    this->mTimerId=0;
}

void Widget::on_pushButton_start_2_clicked()
{
    //定时器1，1秒响一次
    this->mTimerId2 = startTimer(100);
}

void Widget::on_pushButton_stop_2_clicked()
{
    //停止计时器
    killTimer(this->mTimerId2);
    this->mTimerId2=0;
}

void Widget::on_pushButton_start_3_clicked()
{
    QTimer *timer = new QTimer(this);
    connect(timer,&QTimer::timeout,[=](){
        static int num = 1;
        this->ui->lcdNumber_3->display(num++);
    });
    timer->start(10);
}

void Widget::on_pushButton_stop_3_clicked()
{
    timer->stop();
}
