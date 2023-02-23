#include "mylabel.h"
#include <QMouseEvent>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    //默认情况下，窗口不会主动跟踪鼠标
    //只有当某个鼠标按键按下的情况下才开始跟踪
    //如果想一开始跟踪，就要使用以下函数
    this->setMouseTracking(true);

    //事件过滤器的使用
    //1 窗口调用installEventFilter来安装一个事件过滤器
    //2 参数是一个事件过滤器对象QObject，该对象的类要重写eventFilter的函数
    //事件过滤的时候，事件会先到达事件过滤器的eventFilter函数
    //返回值：true表示拦截，false表示不拦截，不拦截情况下事件会继续的到达窗口

    this->installEventFilter(this);
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    //输出鼠标事件一些信息
    //获取坐标
    int x = ev->x();
    int y = ev->y();

    //获取鼠标按键
    Qt::MouseButton btn = ev->button();
    QString strButton ="" ;
    if(btn == Qt::LeftButton)
    {
        strButton = "LeftButton";
    }
    if(btn == Qt::RightButton)
    {
        strButton = "RightButton";
    }
    if(btn == Qt::MidButton)
    {
        strButton = "MidButton";
    }

    //label是可以显示html
    QString str = QString("<h1><center>press[%1,%2][%3]</center></h1>")
            .arg(x).arg(y).arg(strButton);
    this->setText(str);
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    //输出鼠标事件一些信息
    //获取坐标
    int x = ev->x();
    int y = ev->y();

    //获取鼠标按键
    Qt::MouseButtons btns = ev->buttons();
    QString strButton ="" ;
    if(btns & Qt::LeftButton)
    {
        strButton += "LeftButton;";
    }
    if(btns & Qt::RightButton)
    {
        strButton += "RightButton;";
    }
    if(btns & Qt::MidButton)
    {
        strButton += "MidButton";
    }

    //label是可以显示html
    QString str = QString("<h1><center>move[%1,%2][%3]</center></h1>")
            .arg(x).arg(y).arg(strButton);
    this->setText(str);
}

bool MyLabel::event(QEvent *e)
{
    //返回值：true表示该事件得到处理，如果是false，没被处理，事件会继续传递到父窗口
    //QEvent就是所有Event类的父类
    //判断event的类型
//    if(e->type()==QEvent::MouseMove)
//    {
//        //this->mouseMoveEvent(static_cast<QMouseEvent *>(e));
//        return true;
//    }

    return QLabel::event(e);
}

bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    if(event->type()==QEvent::MouseMove)
    {
        //返回true 表示拦截该事件
        return true;
    }
    return false;
}
