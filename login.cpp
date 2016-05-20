#include "login.h"
#include "drawer.h"

LogIn::LogIn(QWidget *parent)
{
    setWindowTitle("QQ2016");
    setWindowIcon(QPixmap(":/images/title.png"));
    usrLbl     = new QLabel(tr("用户名："));
    pswLbl     = new QLabel(tr("密码："));
    usrname    = new QLineEdit;
    password   = new QLineEdit;
    ConfirmBtn = new QPushButton(tr("确定"));
    imagelabel = new QLabel;
    imagelabel->setPixmap(QPixmap(":/images/qiefei.png"));
    //QImage standardsize(":/images/baoman.png");
    //imagelabel->resize(standardsize.size());

    layout     = new QGridLayout();
    layout->addWidget(usrLbl,0,0);
    layout->addWidget(usrname,0,1);
    layout->addWidget(pswLbl,1,0);
    layout->addWidget(password,1,1);
    //layout->setSpacing();
    layout->addWidget(ConfirmBtn,2,2);
    QGridLayout *mainlayout = new QGridLayout(this);
    mainlayout->addWidget(imagelabel,0,0);
    mainlayout->addLayout(layout,0,1);
    mainlayout->setSizeConstraint(QLayout::SetFixedSize);

    connect(ConfirmBtn,SIGNAL(clicked()),this,SLOT(ShowList()));
}

void LogIn::ShowList()
{
    QString user;
    QString pass;
    user = usrname->text();
    pass = password->text();
    if(user=="myf123asd") {
        if(pass=="6636382myf")
        {
            drawer1.resize(250,550);
            drawer1.show();
            close();
        }
    }
}
