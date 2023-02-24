#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    mPoX = 0;
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //painter绘制已经存在的图片
    QPainter painter(this);
    QPixmap pixmap(":/Image/Luffy.png");
    painter.drawPixmap(mPoX,0,pixmap);

}

void Widget::on_pushButton_clicked()
{
    //每点击一次就向右移动图片 10像素
    mPoX += 10;
    //手动触发绘图事件
    //两种方法
    //1 repaint
    //2 update

    //this->repaint();
    this->update();

}
