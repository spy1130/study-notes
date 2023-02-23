#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QPixmap>
#include <QPicture>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    //PixMap作为绘图设备
//    QPixmap pix(300,300);
//    //默认情况下pixmap是黑色填充
//    pix.fill(Qt::white);
//    QPainter painter(&pix);
//    painter.setPen(QColor(255,0,0));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    pix.save("G:\\C7_Qt\\day03\\04_lessonNote\\pix.png");


    //QImage作为绘图设备
//    QImage img(300,300,QImage::Format_RGB32);
//    //默认情况下pixmap是黑色填充
//    img.fill(Qt::white);
//    QPainter painter(&img);
//    painter.setPen(QColor(255,0,0));
//    painter.drawEllipse(QPoint(150,150),100,100);
//    img.save("G:\\C7_Qt\\day03\\04_lessonNote\\img.png");

    //QPicture作为绘图设备
//    QPicture pic;
//    QPainter painter;
//    //开始录制painter绘图步骤
//    painter.begin(&pic);
//    painter.drawEllipse(QPoint(150,150),100,100);
//    painter.end();
//    pic.save("G:\\C7_Qt\\day03\\04_lessonNote\\pic.png");

}
void Widget::paintEvent(QPaintEvent *event)
{
    //先显示一张图片，然后再改它的像素
//    QImage img;
//    img.load(":/Image/Luffy.png");

//    //修改像素
//    for(int x = 50 ; x < 100 ; ++x)
//    {
//        for (int y = 50 ; y<100 ;++y)
//        {
//            img.setPixelColor(x,y,QColor(0,255,0));
//        }
//    }


//    QPainter painter(this);
//    painter.drawImage(0,0,img);



    //重现QPicture的画画步骤
    QPainter painter(this);
    QPicture pic;
    pic.load("G:\\C7_Qt\\day03\\04_lessonNote\\pic.png");
    painter.drawPicture(0,0,pic);
}

Widget::~Widget()
{
    delete ui;
}
