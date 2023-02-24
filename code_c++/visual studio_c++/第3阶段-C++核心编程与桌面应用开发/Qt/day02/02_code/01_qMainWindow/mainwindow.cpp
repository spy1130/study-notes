#include "mainwindow.h"
#include <QMenuBar>
#include <QToolBar>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,600);
    //菜单栏，获取当前窗口的菜单栏，没有的话会自动创建一个
    QMenuBar *mb = this->menuBar();
    //添加菜单
    QMenu *menuFile = mb->addMenu("文件");
    QMenu *menuEdit = mb->addMenu("编辑");
    //往菜单里边添加菜单项
    QAction *actionNew = menuFile->addAction("新建");
    QAction *actionOpen = menuFile->addAction("打开");

    //添加分割符
    menuFile->addSeparator();

    //添加二级菜单
    QMenu *menuRecent = menuFile->addMenu("最近打开的文件");
    menuRecent->addAction("1.txt");

    //工具栏，可以有多个
    QToolBar *toolBar = this->addToolBar("");
    //工具栏添加工具
    toolBar->addAction(actionNew);
    toolBar->addAction(actionOpen);

    //默认停靠在左边
    this->addToolBar(Qt::LeftToolBarArea,toolBar);

    //只允许停靠在左边或者右边
    toolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);

    //设置工具栏不可以浮动
    toolBar->setFloatable(false);

    //设置工具栏不允许拖动
    toolBar->setMovable(false);

    //状态栏，只有一个
    //获取窗口的状态栏，没有的话就创建一个
    QStatusBar *sb = this->statusBar();

    //往状态栏里边添加信息
    //添加左侧信息
    QLabel *labelLeft = new QLabel("左侧信息",this);
    sb->addWidget(labelLeft);
    //添加右侧信息
    QLabel *labelRight = new QLabel("右侧信息",this);
    sb->addPermanentWidget(labelRight);


    //停靠部件，可以有多个
    QDockWidget *dockWidget = new QDockWidget("停靠部件",this);
    //默认情况下没有核心部件作为参照物，停靠部件会占完窗口
    this->addDockWidget(Qt::BottomDockWidgetArea,dockWidget);

    //添加核心部件
    QTextEdit *textEdit = new QTextEdit(this);
    this->setCentralWidget(textEdit);
}

MainWindow::~MainWindow()
{

}
