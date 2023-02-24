#ifndef WIDGET2_H
#define WIDGET2_H

#include <QWidget>

class Widget2 : public QWidget
{
    Q_OBJECT
public:
    explicit Widget2(QWidget *parent = nullptr);

signals:
    void btn2Clicked();

public slots:
};

#endif // WIDGET2_H
