#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

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

void Widget::on_radioButton_clicked()
{
    qDebug()<<ui->radioButton->isChecked();
}

void Widget::on_checkBox_clicked()
{
    //qDebug()<<ui->checkBox->stateChanged();
}

void Widget::on_checkBox_stateChanged(int arg1)
{
    qDebug()<<arg1;
}
