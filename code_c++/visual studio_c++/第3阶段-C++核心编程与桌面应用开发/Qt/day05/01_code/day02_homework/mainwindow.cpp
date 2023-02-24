#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this,"关于这货","这里调用了QMessageBox::about");
}

void MainWindow::on_toolButton_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_toolButton_2_clicked()
{

    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_toolButton_3_clicked()
{

    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_toolButton_4_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_toolButton_5_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_commit_clicked()
{
    //提交表单
    QString content ;
    content  += QString("你的姓名：%1\n").arg(this->ui->lineEdit_name->text());
    content  += QString("你的性别：%1\n").arg(this->ui->radioButton_female->isChecked()?"女":"男");
    content  += QString("你的职业：%1\n").arg(this->ui->comboBox_job->currentText());
    content  += QString("你的年龄：%1\n").arg(this->ui->spinBox_age->text());
    content  += QString("你的生日：%1\n").arg(this->ui->dateEdit_birthday->text());
    if(this->ui->radioButton_vLike->isChecked())
    {
        content  += QString("你的感觉：%1\n").arg("很喜欢");
    }

    if(this->ui->radioButton_preffer->isChecked())
    {
        content  += QString("你的感觉：%1\n").arg("比较喜欢");
    }
    if(this->ui->radioButton_like->isChecked())
    {
        content  += QString("你的感觉：%1\n").arg("喜欢");
    }


    QMessageBox::information(this,"感谢提交",content);
}
