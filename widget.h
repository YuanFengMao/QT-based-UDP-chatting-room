#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHostInfo>
//#include <QtNetwork/QUdpSocket>
//#include<QtNetwork/QHostAddress>
//#include <QNetworkInterface>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QToolButton>
#include <QPushButton>
#include <QTableView>
#include <QTableWidget>
#include "picturebox.h"
#include <QImage>
#include <QTextCursor>
#include <QSplitter>
#include <QColor>

class QUdpSocket;
namespace Ui {
class Widget;
}
enum MsgType{Msg, UsrEnter, UsrLeft, FileName, Refuse, picture1};
class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent , QString usrname);
    ~Widget();
    QString remoteIpStr;
    //void sndMsg(MsgType type, QString srvaddr="");   //广播UDP消息
protected:
    void usrEnter(QString usrname, QString ipaddr);  //新用户加入
    void usrLeft(QString usrname, QString time);     //用户离开
    void sndMsg(MsgType type, QString srvaddr="");   //广播UDP消息
    void closeEvent(QCloseEvent *);   //用户离开广播
    QString getIP();  //获取IP地址
    QString getUsr(); //获取用户名
    QString getMsg(); //获取聊天信息
private:
    Ui::Widget *ui;
    QUdpSocket *udpSocket;
    QHostAddress *remoteHostAddr;
    qint16 port;
    QString uName;
    //QWidget *picture_box;
    //QTableView *picturetable;
  //表情变量
    QPushButton *pic1;
    QPushButton *pic2;
    QPushButton *pic3;
    QPushButton *pic4;
    QPushButton *pic5;
    QPushButton *pic6;
    QPushButton *pic7;
    QPushButton *pic8;
    QGridLayout *pic_layout;
    QWidget *detailbox;
    QString pic_count;  //表情计数

    QColor color;
//插入图片
    QImage image;
    QTextCursor cursor;
    QTextDocument *document;
    QImage iimage;
    QTextCursor icursor;
    QTextDocument *idocument;

private slots:
    void processPendingDatagrams();  //接收UDP消息
    void on_sendBtn_clicked();
    void on_exitBtn_clicked();
    void create_picturebox();
  //表情函数
    void Show_Picturebox();
    void show_picturebox();
    void send_pic1();
    void send_pic2();
    void send_pic3();
    void send_pic4();
    void send_pic5();
    void send_pic6();
    void send_pic7();
    void send_pic8();

    void Clear_Messagebox();
    void on_Size_currentIndexChanged(const QString &arg1);
    void on_Font_currentFontChanged(const QFont &f);
    void on_Color_clicked();
};


#endif // WIDGET_H
