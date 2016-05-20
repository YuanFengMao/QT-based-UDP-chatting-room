#include"drawer.h"
#include<QGroupBox>
#include<QVBoxLayout>

Drawer::Drawer(QWidget *parent, Qt::WindowFlags f)
    :QToolBox(parent,f)
{
    //main window
    setWindowTitle(tr("QQ2016"));
    setWindowIcon(QPixmap(":/images/title.png"));
    //first friend info
    toolBtn1 = new QToolButton;
    toolBtn1->setText(tr("远峰"));   //friend name 1
    toolBtn1->setIcon(QPixmap(":/images/maomao.png"));
    toolBtn1->setIconSize(QPixmap(":/images/baoman.png").size());
    toolBtn1->setAutoRaise(true);
    toolBtn1->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //second friend info
    toolBtn2 = new QToolButton;
    toolBtn2->setText(tr("周杰伦"));   //friend name 2
    toolBtn2->setIcon(QPixmap(":/images/zhoujielun.png"));
    toolBtn2->setIconSize(QPixmap(":/images/baoman.png").size());
    toolBtn2->setAutoRaise(true);
    toolBtn2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //third
    toolBtn3 = new QToolButton;
    toolBtn3->setText(tr("王力宏"));   //friend name 3
    toolBtn3->setIcon(QPixmap(":/images/wanglihong.png"));
    toolBtn3->setIconSize(QPixmap(":/images/baoman.png").size());
    toolBtn3->setAutoRaise(true);
    toolBtn3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn4 = new QToolButton;
    toolBtn4->setText(tr("林丹"));   //friend name 4
    toolBtn4->setIcon(QPixmap(":/images/lindan.png"));
    toolBtn4->setIconSize(QPixmap(":/images/baoman.png").size());
    toolBtn4->setAutoRaise(true);
    toolBtn4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn5 = new QToolButton;
    toolBtn5->setText(tr("刘亦菲"));   //friend name 5
    toolBtn5->setIcon(QPixmap(":/images/liuyifei.png"));
    toolBtn5->setIconSize(QPixmap(":/images/baoman.png").size());
    toolBtn5->setAutoRaise(true);
    toolBtn5->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

    toolBtn6 = new QToolButton;
    toolBtn6->setText(tr("胡歌"));   //friend name 5
    toolBtn6->setIcon(QPixmap(":/images/huge.png"));
    toolBtn6->setIconSize(QPixmap(":/images/baoman.png").size());
    toolBtn6->setAutoRaise(true);
    toolBtn6->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    //layout
    QGroupBox *groupBox = new QGroupBox;
    QVBoxLayout *layout = new QVBoxLayout(groupBox);
    layout->setMargin(20);
    layout->setAlignment(Qt::AlignLeft);
    layout->addWidget(toolBtn1);
    layout->addWidget(toolBtn2);
    layout->addWidget(toolBtn3);
    layout->addWidget(toolBtn4);
    layout->addWidget(toolBtn5);
    layout->addWidget(toolBtn6);
    layout->addStretch();
    this->addItem((QWidget*)groupBox,tr("群成员"));
    //connect
    connect(toolBtn1,SIGNAL(clicked()),this,SLOT(showChatWidget1()));
    connect(toolBtn2,SIGNAL(clicked()),this,SLOT(showChatWidget2()));
    //connect(toolBtn3,SIGNAL(clicked()),this,SLOT(showChatWidget3()));
    //connect(toolBtn4,SIGNAL(clicked()),this,SLOT(showChatWidget4()));
    //connect(toolBtn5,SIGNAL(clicked()),this,SLOT(showChatWidget5()));

   // toolBtn1->setAttribute(Qt::WA_DeleteOnClose);
    //toolBtn2->setAttribute(Qt::WA_DeleteOnClose);
}

void Drawer::showChatWidget1()
{
    chatWidget1 = new Widget(0,toolBtn1->text());
    chatWidget1->setWindowTitle(toolBtn1->text());
    chatWidget1->setWindowIcon(toolBtn1->icon());
    //chatWidget1->resize();
    chatWidget1->show();
    //chatWidget1->setAttribute(Qt::WA_DeleteOnClose);
}
void Drawer::showChatWidget2()
{
    chatWidget2 = new Widget(0,toolBtn2->text());
    chatWidget2->setWindowTitle(toolBtn2->text());
    chatWidget2->setWindowIcon(toolBtn2->icon());
    chatWidget2->show();
    //chatWidget2->setAttribute(Qt::WA_DeleteOnClose);
}
