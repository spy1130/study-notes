#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::treat()
{
    qDebug()<<"Student treat teacher";
}

void Student::treat(QString what)
{
    //QDebug默认将QString转义输出，
    //解决方法两个
    //1 将QString转成 char *
    //qDebug()<<"Student treat teacher with "<<what.toUtf8().data();

    //2 使用qDebug().noquote()
    qDebug().noquote()<<"Student treat teacher with "<<what;
}
