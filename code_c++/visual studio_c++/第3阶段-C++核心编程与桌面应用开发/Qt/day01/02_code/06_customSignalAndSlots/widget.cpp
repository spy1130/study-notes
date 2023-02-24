#include "widget.h"
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
//    自定义信号
//        1 函数声明在类头文件的signals 域下面
//        2 void 类型的函数，没有返回值
//        3 可以有参数，也可以重载
//        4 只有声明，没有实现定义
//        5 触发信号 emit obj->sign(参数...)

//    自定义槽
//        1 函数声明在类头文件的public/private/protected slots域下面（qt4以前的版本）
//            qt5 就可以声明在类的任何位置，还可以是静态成员函数、全局函数、lambda表达式
//        2 void 类型的函数，没有返回值
//        3 可以有参数，也可以重载
//        4 不仅有声明，还得有实现

//    场景：下课了，老师说他饿了，学生就请吃饭
//        信号发送者：老师
//        信号：老师饿了
//        信号接收者：学生
//        槽：请吃饭
//    创多少个类：Teacher Student
//    信号： hungry 1个 Teacher
//    槽：treat 1个 Student

    //老师和学生的两个对象创建
    pTeacher = new Teacher(this);
    pStudent = new Student(this);
    //建立连接
//    connect(pTeacher,&Teacher::hungry,pStudent,&Student::treat);


    //老师说要吃黄焖鸡，学生就请吃黄焖鸡
    //hungry多加一个参数,QString
    //treat 也要一个参数,QString
    //因为函数发生了重载，所以解决
    /*
     * 1 使用函数指针赋值，让编译器挑选符合类型的函数
     * 2 使用static_cast 强制转换，也是让编译器自动挑选符合类型的函数
     */

//    void (Teacher::*teacher_qString)(QString) = &Teacher::hungry;
//    void (Student::*student_qString)(QString) = &Student::treat;

//    connect(pTeacher,teacher_qString,pStudent,student_qString);




    //使用static_cast 来转换无参的函数


    connect(pTeacher,
            static_cast<void (Teacher::*)()>(&Teacher::hungry),
            pStudent,
            static_cast<void (Student::*)()>(&Student::treat));



    //信号可以连接信号
//    QPushButton *btn = new QPushButton("按钮1",this);
//    connect(btn,&QPushButton::clicked,
//            pTeacher,
//            static_cast<void (Teacher::*)()>(&Teacher::hungry));


    //信号可以断开连接
    //disconnect(pTeacher,teacher_qString,pStudent,student_qString);


    //Qt4 的 信号和槽 ，实现teacher和student带参数的信号和槽连接
    connect(pTeacher,SIGNAL(hungry(QString)),pStudent,SLOT(treat(QString)));







    //下课了
    this->classIsOver();
}

void Widget::classIsOver()
{
    //出发老师饿了的信号
    emit pTeacher->hungry();
    //带参数的信号发射
    emit pTeacher->hungry("黄焖鸡\r\n");
}


Widget::~Widget()
{

}

