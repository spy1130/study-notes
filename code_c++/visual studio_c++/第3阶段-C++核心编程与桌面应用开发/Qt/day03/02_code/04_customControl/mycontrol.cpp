#include "mycontrol.h"
#include "ui_mycontrol.h"

MyControl::MyControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyControl)
{
    ui->setupUi(this);
    //设置数值范围
    ui->horizontalSlider->setRange(0,100);
    ui->spinBox->setRange(0,100);

    //建立两个控件的关联
    //滚动滚桥的时候 ，计数器跟着变化
    connect(ui->horizontalSlider,&QSlider::valueChanged,
            [=](int value){
        ui->spinBox->setValue(value);
    });
    //调整计数器的时候，滚桥也跟着变化
    connect(ui->spinBox,static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            ui->horizontalSlider,&QSlider::setValue);
}

MyControl::~MyControl()
{
    delete ui;
}

void MyControl::setValue(int value)
{
    ui->horizontalSlider->setValue(value);
}

int MyControl::value() const
{
    return ui->horizontalSlider->value();
}
