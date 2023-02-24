#ifndef MYCONTROL_H
#define MYCONTROL_H

#include <QWidget>

namespace Ui {
class MyControl;
}

class MyControl : public QWidget
{
    Q_OBJECT

public:
    explicit MyControl(QWidget *parent = 0);
    ~MyControl();

    //定义外部使用的接口
    //设置值，获取值
    void setValue(int value);
    int value()const;

private:
    Ui::MyControl *ui;
};

#endif // MYCONTROL_H
