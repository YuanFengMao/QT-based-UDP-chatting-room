#ifndef DRAWER_H
#define DRAWER_H
#include<QToolBox>
#include<QToolButton>
#include<QTextEdit>
#include<QVBoxLayout>
#include<QPushButton>
#include"widget.h"

class Drawer : public QToolBox
{
    Q_OBJECT
public:
    Drawer(QWidget *parent=0, Qt::WindowFlags f=0);
    //Widget *chatWidget1;
private:
    //main window
    QToolButton *toolBtn1;
    QToolButton *toolBtn2;
    QToolButton *toolBtn3;
    QToolButton *toolBtn4;
    QToolButton *toolBtn5;
    QToolButton *toolBtn6;
    QToolButton *toolBtn7;
    QToolButton *toolBtn8;
    QToolButton *toolBtn9;
    Widget *chatWidget1;
    Widget *chatWidget2;
private slots:
    void showChatWidget1();
    void showChatWidget2();
};

#endif // DRAWER_H
