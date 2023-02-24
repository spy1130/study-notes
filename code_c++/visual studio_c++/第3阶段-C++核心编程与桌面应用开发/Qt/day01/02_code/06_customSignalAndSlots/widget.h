#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "student.h"
#include "teacher.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void classIsOver();

private:
    Teacher *pTeacher;
    Student *pStudent;
};

#endif // WIDGET_H
