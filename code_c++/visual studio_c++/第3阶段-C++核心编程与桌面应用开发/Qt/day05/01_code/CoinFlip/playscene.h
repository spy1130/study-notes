#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include "mymainwindow.h"
#include "coinbutton.h"

class PlayScene : public MyMainWindow
{
    Q_OBJECT
public:
    PlayScene(int level,QWidget *parent = nullptr);
    //翻动row行，col列的硬币
    void flip(int row ,int col);
    //判断胜利
    void judgeWin();

signals:
    //点击返回按钮发射的信号
    void backBtnClicked();

protected:
    void paintEvent(QPaintEvent *event);

public slots:
private:
    //胜利的状态
    bool mHasWin;
    //硬币按钮数组
    CoinButton *mCoins[4][4];
};

#endif // PLAYSCENE_H
