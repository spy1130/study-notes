#include "widget2.h"
#include <QPushButton>

Widget2::Widget2(QWidget *parent) : QWidget(parent)
{
    resize(800,600);
    QPushButton *btn2 = new QPushButton("按钮2",this);
    connect(btn2,&QPushButton::clicked,[=](){
        //切换到窗口1
        //自定义一个信号，点击按钮的时候触发
        emit this->btn2Clicked();
    });
}
