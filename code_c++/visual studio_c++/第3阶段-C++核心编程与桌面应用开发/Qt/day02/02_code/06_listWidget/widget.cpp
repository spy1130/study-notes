#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //往listWidget里边添加内容
//    QListWidgetItem *item = new QListWidgetItem("床前明月光");
//    item->setTextAlignment(Qt::AlignHCenter);
//    ui->listWidget->addItem(item);
    //QString -> std::string  QList -> std::list   QStringList -> std::list<std::string>
    QStringList list;
    list<<"床前明月光"<<"疑似地上霜"<<"举头望明月"<<"低头思故乡";

    ui->listWidget->addItems(list);
}

Widget::~Widget()
{
    delete ui;
}
