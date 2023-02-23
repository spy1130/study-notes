#ifndef HELLOWIDGET_H
#define HELLOWIDGET_H

#include <QWidget>

class HelloWidget : public QWidget
{
    //宏，引入qt信号和槽的一个宏
    Q_OBJECT

public:
    //parent窗口指针，父窗口对象的指针
    //如果parent为0或者NULL，表示当前窗口对象是个顶层窗口
    //顶层窗口就是在任务栏可以找到的窗口
    HelloWidget(QWidget *parent = 0);
    ~HelloWidget();
};

#endif // HELLOWIDGET_H
