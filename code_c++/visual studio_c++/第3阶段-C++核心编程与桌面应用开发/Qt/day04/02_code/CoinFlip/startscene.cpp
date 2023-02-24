#include "startscene.h"
#include <QPushButton>
#include "mypushbutton.h"
#include <QTimer>

StartScene::StartScene(QWidget *parent) : MyMainWindow(parent)
{
    this->setWindowTitle("开始场景");

    MyPushButton *btnStart =
            new MyPushButton(":/res/MenuSceneStartButton.png",
                             ":/res/MenuSceneStartButton.png",this);
    btnStart->resize(114,114);
    //按钮水平居中，垂直方向在3/4位置
    //计算方式 x=  窗口宽度/2 - 按钮宽度/2 ,  y= 窗口高度*3/4 - 按钮高度/2
    btnStart->move((this->width()-btnStart->width())/2,
                   this->height()*3/4-btnStart->height()/2);

    connect(&this->mSelectScene,&SelectScene::backBtnClicked,[=](){
        //当第二个窗口的返回按钮点击的时候，显示当前窗口，隐藏第二个窗口
        this->show();
        this->mSelectScene.hide();
    });
    connect(btnStart,&MyPushButton::clicked,[=](){
        //将按钮设置为不可用
        btnStart->setEnabled(false);
        //播放向下的动画
        btnStart->moveDonw();

        QTimer::singleShot(150,[=](){
            //往上走的动画会覆盖之前的动画，
            //要等待之前动画播放完再调用
            btnStart->moveUp();
        });
        QTimer::singleShot(300,[=](){
            //将按钮设置为可用
            btnStart->setEnabled(true);

            //场景转换
            //隐藏当前窗口
            this->hide();
            //显示第二个窗口
            this->mSelectScene.show();
        });
    });
}
