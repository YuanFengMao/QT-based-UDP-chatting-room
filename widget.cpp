#include "ui_widget.h"
#include "widget.h"
#include <qdatetime.h>
#include <QUdpSocket>
#include <QHostInfo>
#include <QMessageBox>
#include <QScrollBar>
#include <QDateTime>
#include <QNetworkInterface>
#include <QProcess>
#include <QTableView>
#include <QDirModel>
#include <QSplitter>
#include <QColorDialog>
//#include <QFont>
//#include <QTime>

Widget::Widget(QWidget *parent,QString usrname):
      QWidget(parent)
    ,ui(new Ui::Widget)
{
    ui->setupUi(this);
    uName=usrname;
    udpSocket=new QUdpSocket(this);
    port=23239;
    //QString Qport=port;
    //ui->messagebox->setText("a"+port);

    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
    connect(udpSocket,SIGNAL(readyRead()),this,SLOT(processPendingDatagrams()));
    //connect(udpSocket,SIGNAL(readyRead()),this,SLOT(usrEnter()));
    sndMsg(UsrEnter);  //有用户进入，初始化

    //ui->Emoji->setIcon(QPixmap(":/images/biaoqing.png"));
   // ui->Emoji->setIconSize(ui->Emoji->size());


    connect(ui->Emoji,SIGNAL(clicked()),this,SLOT(Show_Picturebox()));
    connect(ui->Clear,SIGNAL(clicked()),this,SLOT(Clear_Messagebox()));
    create_picturebox();

    //QTextCursor cursor = ui->messagebox->textCursor();
}

void Widget::create_picturebox()
{
    detailbox = new QWidget;
    detailbox->setWindowFlags(Qt::CustomizeWindowHint);
    pic1 = new QPushButton;
    pic1->setIcon(QPixmap(":/images/baoman.png"));
    pic2 = new QPushButton;
    pic2->setIcon(QPixmap(":/images/me.png"));
    pic3 = new QPushButton;
    pic3->setIcon(QPixmap(":/images/huaixiao.png"));
    pic4 = new QPushButton;
    pic4->setIcon(QPixmap(":/images/xiaoku.png"));
    pic5 = new QPushButton;
    pic5->setIcon(QPixmap(":/images/ku.png"));
    pic6 = new QPushButton;
    pic6->setIcon(QPixmap(":/images/yumen.png"));
    pic7 = new QPushButton;
    pic7->setIcon(QPixmap(":/images/keai.png"));
    pic8 = new QPushButton;
    pic8->setIcon(QPixmap(":/images/shuai.png"));

    QGridLayout *pic_layout = new QGridLayout(detailbox);
    pic_layout->addWidget(pic1,0,0);
    pic_layout->addWidget(pic2,0,1);
    pic_layout->addWidget(pic3,0,2);
    pic_layout->addWidget(pic4,0,3);
    pic_layout->addWidget(pic5,1,0);
    pic_layout->addWidget(pic6,1,1);
    pic_layout->addWidget(pic7,1,2);
    pic_layout->addWidget(pic8,1,3);
    detailbox->hide();
    connect(pic1,SIGNAL(clicked()),this,SLOT(send_pic1()));
    connect(pic2,SIGNAL(clicked()),this,SLOT(send_pic2()));
    connect(pic3,SIGNAL(clicked()),this,SLOT(send_pic3()));
    connect(pic4,SIGNAL(clicked()),this,SLOT(send_pic4()));
    connect(pic5,SIGNAL(clicked()),this,SLOT(send_pic5()));
    connect(pic6,SIGNAL(clicked()),this,SLOT(send_pic6()));
    connect(pic7,SIGNAL(clicked()),this,SLOT(send_pic7()));
    connect(pic8,SIGNAL(clicked()),this,SLOT(send_pic8()));
}

Widget::~Widget()
{
    delete ui;
}

// 使用UDP广播发送信息，MessageType是指头文件中的枚举数据类型
//sendMessage即把本机的主机名，用户名+（消息内容后ip地址）广播出去
void Widget::sndMsg(MsgType type, QString srvaddr)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    QString address=getIP();

    //udpSocket->writeDatagram(out,QHostAddress::Broadcast,port);

    //ui->messagebox->setText(address);

    out<< type << getUsr();
    //ui->messagebox->append(getUsr());

    switch(type)
    {
    case Msg:
        if(ui->send_message->toPlainText()=="") {
            QMessageBox::warning(0,tr("警告"),tr("发送内容不能为空"),QMessageBox::Ok);
        return;
        }
        out << address <<getMsg();
        ui->messagebox->verticalScrollBar()->setValue(
                    ui->messagebox->verticalScrollBar()->maximum());

        break;
    case UsrEnter: { out<<address; break; }
    case UsrLeft: break;
    case FileName: break;
    case Refuse: break;
    case picture1: { out<<address<<pic_count; break; }
    }
    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
/*
    QString usrIp="10.138.76.232";
    if(uName=="周杨松")  {
        usrIp = "10.138.76.232";
        remoteIpStr = usrIp;
        remoteHostAddr = new QHostAddress(remoteIpStr);
    }
    else if(uName=="队长") {
        usrIp = "192.168.45.180";
        remoteIpStr = usrIp;
        remoteHostAddr = new QHostAddress(remoteIpStr);
    }
    udpSocket->writeDatagram(data, data.length(), *remoteHostAddr, port);
*/
    //remoteIpStr = "10.138.76.232";  //彤神电脑IP
    /*
    remoteIpStr = usrIp;
    remoteHostAddr = new QHostAddress(remoteIpStr);
    udpSocket->writeDatagram(data, data.length(), *remoteHostAddr, port);
    */
}

//接收UDP广播
void Widget::processPendingDatagrams()
{
    //udpSocket->writeDatagram(msg. QHostAddress::Broadcast,port);
    //ui->messagebox->setValue(udpSocket->hasPendingDatagrams());
    while(udpSocket->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(datagram.data(),datagram.size());
        QDataStream in(&datagram,QIODevice::ReadOnly);
        int msgType;
        in >> msgType;
        QString usrName,ipAddr,msg;
        //QTime DataTime=QTime::currentTime();
        //QString  time=DataTime.toString("yyyy-MM-dd hh:mm:ss");
        QString time=QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        switch(msgType)
        {
        case Msg:
            in >> usrName >> ipAddr >> msg;
            ui->messagebox->setTextColor(Qt::blue);
            ui->messagebox->setCurrentFont(QFont("Times New Roman",12));
            ui->messagebox->append("["+usrName+"]"+time);
            ui->messagebox->append(msg);
            break;
        case UsrEnter:
            in >> usrName >>ipAddr;
            usrEnter(usrName,ipAddr);
            break;
        case UsrLeft:
            in >> usrName;
            usrLeft(usrName,time);
            break;
        case FileName: {break;}
        case Refuse: {break;}
        case picture1: {
            QString pic="";
            in >> usrName >> ipAddr >> pic;
            ui->messagebox->setTextColor(Qt::blue);
            ui->messagebox->setCurrentFont(QFont("Times New Roman",12));
            ui->messagebox->append("["+usrName+"]"+time);
            //ui->messagebox->append(usrName+ipAddr+pic);
//插入图片
            if(pic=="baoman") {
                image.load(":/images/baoman.png");
                pic_count="";
            }
            else if(pic=="me") {
                //QImage iimage;
                image.load(":/images/me.png");
                pic_count="";
            }
            else if(pic=="huaixiao") {
                image.load(":/images/huaixiao.png");
            }
            else if(pic=="xiaoku") {
                image.load(":/images/xiaoku.png");
            }
            else if(pic=="yumen") {
                //QImage iimage;
                image.load(":/images/yumen.png");
                pic_count="";
            }
            else if(pic=="ku") {
                image.load(":/images/ku.png");
            }
            else if(pic=="keai") {
                image.load(":/images/keai.png");
            }
            else if(pic=="shuai") {
                image.load(":/images/shuai.png");
            }

            ui->messagebox->append("");
            cursor = ui->messagebox->textCursor();
                //document = ui->messagebox->document();
            // 下面的addResource代码非常重要, 内存增加很少
            cursor.movePosition(QTextCursor::End);
                //document->addResource(QTextDocument::ImageResource, QUrl("iimage"), iimage);
            cursor.insertImage(image);
            cursor.movePosition(QTextCursor::EndOfLine);

        }

        }
    }
}

//用户进入
void Widget::usrEnter(QString usrname, QString ipaddr)
{
    bool isEmpty=ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).isEmpty();
    if(isEmpty){
        QTableWidgetItem *usr = new QTableWidgetItem(usrname);
        QTableWidgetItem *ip = new QTableWidgetItem(ipaddr);
        ui->usrTblWidget->insertRow(0);
        ui->usrTblWidget->setItem(0,0,usr);
        ui->usrTblWidget->setItem(0,1,ip);

        ui->messagebox->setTextColor(Qt::gray);
        ui->messagebox->setCurrentFont(QFont("Times New Roman",10));
        ui->messagebox->append(usrname+"上线！\n");
        ui->usrNumLbl->setText(tr("在线人数：%1").arg(ui->usrTblWidget->rowCount()));
        sndMsg(UsrEnter);  //使其他端点用户在列表中加入该用户
    }
    //else
    //    ui->usrNumLbl->setText(tr("没有人！"));
}

//用户离开
void Widget::usrLeft(QString usrname, QString time)
{
    int rowNum = ui->usrTblWidget->findItems(usrname,Qt::MatchExactly).first()->row();
    ui->usrTblWidget->removeRow(rowNum);
    ui->messagebox->setTextColor(Qt::gray);
    ui->messagebox->setCurrentFont(QFont("Times New Roman",10));
    ui->messagebox->append(tr("%1于%2离开！").arg(usrname).arg(time));
    ui->usrNumLbl->setText(tr("在线人数：%1").arg(ui->usrTblWidget->rowCount()));
}

QString Widget::getIP()
{
    QList<QHostAddress>list = QNetworkInterface::allAddresses();
    foreach (QHostAddress addr,list) {
        if(addr.protocol()==QAbstractSocket::IPv4Protocol)
            return addr.toString();
    }
    return 0;
}

QString Widget::getUsr()
{
    return uName;
}

//获取文本框内容
QString Widget::getMsg()
{
    QString msg=ui->send_message->toHtml();
    ui->send_message->clear();
    ui->send_message->setFocus();

    //接收正常
    //ui->messagebox->append(msg);
    return msg;
}

//按发送键发送
void Widget::on_sendBtn_clicked()
{
    sndMsg(Msg);
    //
   // udpSocket->writeDatagram(0,0,QHostAddress::Broadcast,port);
}

void Widget::on_exitBtn_clicked()
{
    close();
}

//用户离开
void Widget::closeEvent(QCloseEvent *e)
{
    sndMsg(UsrLeft);  //发送广播
    QWidget::closeEvent(e); //使其他端点在其用户列表中删除该用户
}

//显示/不显示表情包
void Widget::show_picturebox()
{
    if(detailbox->isHidden()) {
        detailbox->move(450,350);
        detailbox->show();
    }
    else
        detailbox->hide();
}



/*
//增加图片效果
void Widget::on_pushButton_clicked()
{
    QImage image(":/images/baoman.png");
    QTextCursor cursor = ui->messagebox->textCursor();
        QTextDocument *document = ui->messagebox->document();
        // 下面的addResource代码非常重要, 内存增加很少
        cursor.movePosition(QTextCursor::End);
        document->addResource(QTextDocument::ImageResource, QUrl("image"), image);
        // edit->setAlignment(Qt::AlignCenter);
        cursor.insertImage("image");
  //  ui->messagebox->append("<img src=/"baoman.png/n);   //"<img src=/"1.png/n
}
*/

//点开表情包

void Widget::Show_Picturebox()
{
    //sndMsg(picture);
    show_picturebox();
}


//发送表情
void Widget::send_pic1()
{
    pic_count="baoman";
    sndMsg(picture1);
}
void Widget::send_pic2()
{
    pic_count="me";
    sndMsg(picture1);
}
void Widget::send_pic3()
{
    pic_count="huaixiao";
    sndMsg(picture1);
}
void Widget::send_pic4()
{
    pic_count="xiaoku";
    sndMsg(picture1);
}
void Widget::send_pic5()
{
    pic_count="ku";
    sndMsg(picture1);
}
void Widget::send_pic6()
{
    pic_count="yumen";
    sndMsg(picture1);
}
void Widget::send_pic7()
{
    pic_count="keai";
    sndMsg(picture1);
}
void Widget::send_pic8()
{
    pic_count="shuai";
    sndMsg(picture1);
}

//清空发送框
void Widget::Clear_Messagebox()
{
    ui->messagebox->clear();
}

//更改字体
void Widget::on_Font_currentFontChanged(const QFont &f)
{
     ui->send_message->setCurrentFont(f);
     ui->send_message->setFocus();
}

//更改字大小
void Widget::on_Size_currentIndexChanged(const QString &arg1)
{
    ui->send_message->setFontPointSize(arg1.toDouble());
    ui->send_message->setFocus();
}

//颜色设置
void Widget::on_Color_clicked()
{
    color = QColorDialog::getColor(color,this);
    if(color.isValid()) {
        ui->send_message->setTextColor(color);
        ui->send_message->setFocus();
    }
}
