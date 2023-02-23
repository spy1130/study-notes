#include "widget.h"
#include "ui_widget.h"
#include <QFile>
#include <QFileDialog>
#include <QTextCodec>
#include <QFileInfo>
#include <QDebug>
#include <QDateTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    //写文件
    QFile file("G:\\C7_Qt\\day04\\04_lessonNote\\text.txt");
    file.open(QIODevice::WriteOnly|QIODevice::Append);
    file.write("hello");
    file.close();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,"打开一个txt",
                                 "G:\\C7_Qt\\day03\\03_resources","TXT (*.txt)");
    //对filename做判断，如果没有选择文件，那么就是个空串
    if(fileName.isEmpty())
    {
        return ;
    }
    //不为空串，选择了某个文件，将文件名显示到lineEdit
    this->ui->lineEdit->setText(fileName);

    //使用qfile来读取文件
    QFile file(fileName);
    //打开文件
    file.open(QIODevice::ReadOnly);

    //读取文件的内容
    //将所有内容全部读取出来
//    QByteArray array = file.readAll();
    QByteArray array;

    do
    {
        //单行读取
        array += file.readLine();
    }while(!file.atEnd());


    //将QByteArray转化成QStirng
//    QString content = QString(array);

    //使用gbk编码
    QTextCodec *codec = QTextCodec::codecForName("gbk");

    //将array转化到QString
    QString content = codec->toUnicode(array);

    //输出到edit上
    this->ui->plainTextEdit->setPlainText(content);


    //获取文件信息
    QFileInfo info(fileName);
    qDebug()<<"文件全名:"<<info.fileName();
    qDebug()<<"baseName:"<<info.baseName();
    qDebug()<<"创建时间:"<<info.created().toString("yyyy-mm-dd");
    qDebug()<<"最后修改时间:"<<info.lastModified();

    //关闭文件
    file.close();


}
