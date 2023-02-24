#include "widget.h"
#include <QPushButton>
#include "widget2.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(500,400);
    this->setWindowTitle("窗口1");
    QPushButton *btn = new QPushButton("按钮1",this);
    widget2 = new Widget2;
    connect(btn,&QPushButton::clicked,[=](){
        //点击按钮1，将窗口2显示出来
        widget2->show();
        //隐藏窗口1
        this->hide();
    });

    connect(widget2,&Widget2::btn2Clicked,[=](){
        //收到第二个按钮点击的信号就将第二个窗口隐藏并且将自己显示出来
        this->show();
        widget2->hide();
    });
}

Widget::~Widget()
{
    delete widget2;
}
