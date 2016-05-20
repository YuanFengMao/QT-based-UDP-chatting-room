#include "widget.h"
#include <QApplication>
#include "drawer.h"
#include <QTextCodec>
#include "login.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());//对不同的文字选择不同的编码
   // Widget w;
   // w.show();
    /*
    Drawer drawer;
    drawer.resize(250,550);
    drawer.show();
    */
    LogIn Login(0);
    Login.setWindowTitle("QQ2016");
    Login.show();

    return a.exec();
}
