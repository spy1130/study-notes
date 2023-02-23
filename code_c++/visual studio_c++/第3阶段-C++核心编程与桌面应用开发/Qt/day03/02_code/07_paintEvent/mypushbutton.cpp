#include "mypushbutton.h"
#include <QDebug>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

void MyPushButton::paintEvent(QPaintEvent *ev)
{
//    static int num = 1;
//    qDebug()<<num++;
    QPushButton::paintEvent(ev);
}
