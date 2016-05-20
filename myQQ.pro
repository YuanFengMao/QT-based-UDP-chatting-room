#-------------------------------------------------
#
# Project created by QtCreator 2016-05-13T14:32:41
#
#-------------------------------------------------

QT       += core gui
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = myQQ
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    drawer.cpp \
    login.cpp

HEADERS  += widget.h \
    drawer.h \
    login.h

FORMS    += widget.ui

RESOURCES += \
    myword.qrc


