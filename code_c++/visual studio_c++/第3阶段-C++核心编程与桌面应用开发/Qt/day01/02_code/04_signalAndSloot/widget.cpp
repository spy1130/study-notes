#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *btn = new QPushButton("按钮1",this);
    //关闭 this->close()

//    按钮
//    被点击
//    窗口
//    关闭

//    建立四者的关系(按钮 被点击 窗口 关闭)

    //信号发送者
    //信号
    //信号接收者
    //槽：信号的处理动作
    //通过connect 建立四者的关系
    // conncet(信号发送者，信号，信号接收者，槽)


    //保留&符号
    //1 提高代码可读性
    //2 自动提示
    connect(btn,&QPushButton::clicked,this,&Widget::close);

}

Widget::~Widget()
{

}
