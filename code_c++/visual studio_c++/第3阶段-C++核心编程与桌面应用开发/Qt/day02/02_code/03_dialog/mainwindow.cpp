#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionModal,&QAction::triggered,[=](){
        //创建一个模态对话框
        QDialog dlg(this);
        dlg.exec();
        qDebug()<<"hello dialog";
    }
    );

    connect(ui->actionNonModal,&QAction::triggered,[=](){
        //创建一个非模态对话框
        //因为show是非阻塞的函数，所以dlg会很快释放，改用new
        QDialog *dlg = new QDialog(this);
        //释放问题，只有父对象释放的时候子对象才释放
        //通过设置窗口的属性，让它关闭的时候自动释放
        dlg->setAttribute(Qt::WA_DeleteOnClose);
        dlg->show();
        qDebug()<<"hello dialog";
    }
    );
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCritical_triggered()
{
    QMessageBox::critical(this,"错误","critical");
}

void MainWindow::on_actionWarning_triggered()
{
    QMessageBox::warning(this,"警告","warning");
}

void MainWindow::on_actionInfo_triggered()
{
    QMessageBox::information(this,"信息","information");
}

void MainWindow::on_actionQuestion_triggered()
{
    //点击了ok就打印
    if(QMessageBox::Ok==
            QMessageBox::question(this,"问你个事","你有对象吗？",
                          QMessageBox::Ok|QMessageBox::Cancel))
    {
        qDebug()<<"点击了Ok";
    }
    else
    {
        qDebug()<<"点击了cancel";
    }
}

void MainWindow::on_actionQFileDialog_triggered()
{
    //打开一个文件对话框
    QString fileName = QFileDialog::getOpenFileName(this,"打开一个文件",
                                 "G:\\C7_Qt\\day02\\03_resources\\Image",
                                 "PNG (*.png) ;; JPG (*.jpg) ;; GIF (*.gif) ;; all (*.*)");
    qDebug()<<fileName;
}
