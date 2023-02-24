#include "widget.h"
#include <QDebug>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //lambda表达式
//    [capture](parameters) opt ->retType
//    {
//    ……;
//    }

    //调用lambda的方式，使用函数指针
//    void (*p)()=
//    []()
//    {
//        qDebug()<<"Hello  Lambda";
//    };
//    p();


    //局部变量捕获


    int a = 10;
    int b = 20;
    int c = 20;
    int d = 20;
    int e = 20;
    int f = 20;
    //捕获局部变量分两种方式，一种是值传递，一种引用
    //默认情况下值传递捕获进来的局部变量就是const
    //= 局部变量全部使用值传递捕获 捕获局部变量包括this
    //& 局部变量全部使用应用传递捕获进来
//    [=,&b]() mutable
//    {
//        qDebug()<<"Hello  Lambda";
//        qDebug()<<a<<b;
//        a=20;
//        b=30;
//    }();

//    qDebug()<<a<<b;

    //信号和槽使用lambda

    QPushButton *btn = new QPushButton("按钮1",this);
    //以后都使用[=](){}的形式

    connect(btn,&QPushButton::clicked,[=](){
//        qDebug()<<a<<b;
//        this->close();
        this->resize(800,600);
    });
}

Widget::~Widget()
{

}
