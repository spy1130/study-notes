#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //关联ui文件到程序界面
    ui->setupUi(this);

    //往状态栏添加信
    ui->statusBar->addWidget(new QLabel("左侧信息",this));

    //使用图片资源
    //1 使用绝对路径
//    ui->actionNew->setIcon(QIcon("G:\\C7_Qt\\day02\\03_resources\\Image\\Luffy.png"));
    //2 使用资源文件
    //使用资源的路径形式：
    //  冒号: + 前缀 / + 目录文件名
    ui->actionNew->setIcon(QIcon(":/Image/Luffy.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}
