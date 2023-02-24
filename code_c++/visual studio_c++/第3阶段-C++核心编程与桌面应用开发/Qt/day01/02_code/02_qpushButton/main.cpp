#include "widget.h"
#include <QApplication>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    //添加按钮
//    QPushButton btn;
//    btn.setText("按钮1");
//    //将按钮显示出来
//    btn.show();

    //默认情况下没有建立父子关系，显示的都是顶层窗口
    //要建立父子关系
    //1 setParent函数
    QPushButton btn;
    btn.setText("按钮1");
    btn.setParent(&w);
    //2 构造函数传参
    QPushButton btn2("按钮2",&w);
    //移动以下按钮位置
    btn2.move(100,100);

    //重新设置窗口大小
    btn2.resize(400,400);


    //按钮3，和按钮2建立父子关系
    QPushButton btn3("按钮3",&btn2);
    btn3.move(100,100);



    //设置窗口标题
    w.setWindowTitle("HelloWorld");

    //设置窗口的固定大小
//    w.setFixedSize(800,600);

    //同时设置窗口对的位置和大小
    w.setGeometry(400,400,500,500);


    w.show();
    //顶层窗口移动到200,100
//    w.move(200,100);

    return a.exec();
}
