#-------------------------------------------------
#
# Project created by QtCreator 2018-01-05T09:33:22
#
#-------------------------------------------------

# Qt是 工程模块变量，引入了 qt的core 和 gui模块
QT       += core gui

#如果qt版本号大于4，就引入widgets模块
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


#指定目标，生成可执行程序的名字
TARGET = 01_hello
#模板，生成什么文件，app表示应用程序exe,lib 就是生成库
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.'
# 如果你用了过时的api，就会报warning
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        hellowidget.cpp

HEADERS += \
        hellowidget.h
