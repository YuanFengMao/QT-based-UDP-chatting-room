#include "picturebox.h"
#include "widget.h"
#include "drawer.h"
#include <QGridLayout>

picturebox::picturebox(QWidget *parent)
{
    pic1 = new QToolButton;
    pic1->setText(tr("baoman"));
    pic1->setIcon(QPixmap(":/images/baoman.png"));
    pic2 = new QToolButton;
    pic2->setText(tr("kenan"));
    pic2->setIcon(QPixmap(":/images/kenan.png"));
    //QGroupBox *picturebox = new QGroupBox;
    picture_layout = new QGridLayout(this);
    picture_layout->addWidget(pic1,0,0);
    picture_layout->addWidget(pic2,0,1);
    connect(pic1,SIGNAL(clicked()),this,SLOT(send_picture1()));
    connect(pic2,SIGNAL(clicked()),this,SLOT(send_picture2()));

    ui->setupUi(this);
    uName=usrname;
    udpSocket=new QUdpSocket(this);
    port=23239;
    //QString Qport=port;
    //ui->messagebox->setText("a"+port);

    udpSocket->bind(port,QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
}

void Widget::sndMsg(MsgType type, QString srvaddr)
{
    QByteArray data;
    QDataStream out(&data, QIODevice::WriteOnly);
    QString address=getIP();

    //udpSocket->writeDatagram(out,QHostAddress::Broadcast,port);

    //ui->messagebox->setText(address);

    out<< type << getUsr();
    //ui->messagebox->append(getUsr());

    udpSocket->writeDatagram(data,data.length(),QHostAddress::Broadcast,port);
}

void picturebox::send_picture1()
{
    //parent->sndMsg(picture);
    //QByteArray data;
    //QDataStream out(&data, QIODevice::WriteOnly);
    //QString address=getIP();

    //udpSocket->writeDatagram(out,QHostAddress::Broadcast,port);

    //ui->messagebox->setText(address);

    //out<< picture << "周杨松";
}
void picturebox::send_picture2()
{
   sndMsg(picture);
}
