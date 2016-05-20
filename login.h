#ifndef LOGIN_H
#define LOGIN_H
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include "drawer.h"

class LogIn : public QWidget
{
    Q_OBJECT
public:
    LogIn(QWidget *parent);
   // ~LogIn();
private:
    QLabel      *usrLbl;
    QLabel      *pswLbl;
    QPushButton *ConfirmBtn;
    QLineEdit   *usrname;
    QLineEdit   *password;
    QImage       image;
    QLabel      *imagelabel;
    QGridLayout *layout;
    QGridLayout *mainlayout;

    Drawer       drawer1;
private slots:
    void ShowList();
};

#endif // LOGIN_H
