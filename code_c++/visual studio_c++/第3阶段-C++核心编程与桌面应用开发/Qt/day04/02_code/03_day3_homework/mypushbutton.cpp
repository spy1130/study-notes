#include "mypushbutton.h"
#include <QPainter>
#include <QBrush>
#include <QMouseEvent>

MyPushButton::MyPushButton(QWidget *parent) : QPushButton(parent)
{

}

void MyPushButton::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);

    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    switch(mStat)
    {
    case Normal:
        //填充红色
        brush.setColor(Qt::red);
        break;
    case Entered:
        //填充绿色
        brush.setColor(Qt::green);
        break;
    case Pressed:
        //填充蓝色
        brush.setColor(Qt::blue);
        break;
    }

    //画家设置画刷
    painter.setBrush(brush);


    //画按钮
    //画椭圆
    painter.drawEllipse(0,0,this->width()-1,this->height()-1);
    //画按钮的文字
    painter.drawText(0,0,this->width(),this->height(),
                     Qt::AlignHCenter|Qt::AlignVCenter,this->text());
}

void MyPushButton::enterEvent(QEvent *event)
{
    //将状态设置Entered
    this->mStat = Entered;
    update();
}

void MyPushButton::leaveEvent(QEvent *event)
{
    //将状态设置Normal
    this->mStat = Normal;
    update();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    //将状态设置Pressed，只有左键才触发
    if(e->button()!=Qt::LeftButton)
        return;
    this->mStat = Pressed;
    update();

    //其实信号依赖于事件
    QPushButton::mousePressEvent(e);
}

void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    //将状态设置Entered，只有左键才触发
    if(e->button()!=Qt::LeftButton)
        return;
    this->mStat = Entered;
    update();
    QPushButton::mouseReleaseEvent(e);
}
