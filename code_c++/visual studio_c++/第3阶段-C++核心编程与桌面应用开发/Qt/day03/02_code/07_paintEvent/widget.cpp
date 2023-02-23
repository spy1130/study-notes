#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //在这里画画
    QPainter painter(this);

    //画家偏移，搬动画家到某个坐标上开始画画
    painter.translate(100,0);

    //创建一支画笔
    QPen pen;
    pen.setColor(QColor(255,0,0));
    //设置笔宽
    pen.setWidth(3);
    //设置画笔的风格
    pen.setStyle(Qt::DashLine);

    //画家设置画笔
    painter.setPen(pen);

    //需要填充，使用画刷
    QBrush brush;
    brush.setColor(Qt::cyan);
    //默认情况下，画刷不填充，还得设置风格
    brush.setStyle(Qt::Dense4Pattern);

    //画家设置画刷
    painter.setBrush(brush);

    //画一条线
    painter.drawLine(0,0,100,100);

    //画矩形
    painter.drawRect(20,20,50,50);

    //画圆形，使用椭圆
    painter.drawEllipse(QPoint(100,100),50,50);

    //画文字
    painter.drawText(200,100,"好好学习，天天向上");



}
