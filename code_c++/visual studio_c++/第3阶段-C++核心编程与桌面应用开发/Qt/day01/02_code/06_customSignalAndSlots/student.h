#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

signals:

public slots:

    //    自定义槽
    //        1 函数声明在类头文件的public/private/protected slots域下面（qt4以前的版本）
    //            qt5 就可以声明在类的任何位置，还可以是静态成员函数、全局函数、lambda表达式
    //        2 void 类型的函数，没有返回值
    //        3 可以有参数，也可以重载
    //        4 不仅有声明，还得有实现

    //学生请吃饭
    void treat();
    void treat(QString what);
};

#endif // STUDENT_H
