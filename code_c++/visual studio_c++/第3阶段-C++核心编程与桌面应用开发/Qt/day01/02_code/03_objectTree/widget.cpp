#include "widget.h"
#include <QPushButton>
#include "mypushbutton.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //局部变量在函数退出的时候就会自动释放
//    QPushButton btn("按钮1",this);
//    btn.show();

    //解决 让按钮的生命周期长一点
    //1 static
    //2 类成员变量
    //3 new 一个，动态内存分配
    MyPushButton *btn1 = new MyPushButton(this);
    btn1->setText("按钮1");
    //没有delete

    //验证析构
    //再继承一个按钮类，在子类的析构函数里边打log

}

Widget::~Widget()
{

}
