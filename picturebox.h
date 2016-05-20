#ifndef PICTUREBOX_H
#define PICTUREBOX_H
#include <QGroupBox>
#include <QGridLayout>
#include <QToolButton>
#include "widget.h"

class picturebox : public QWidget
{
    Q_OBJECT
public:
    picturebox(QWidget *parent);
private:
    //QGroupBox picturebox;
    QGridLayout *picture_layout;
    QToolButton *pic1;
    QToolButton *pic2;
private slots:
    void send_picture1();
    void send_picture2();
};

#endif // PICTUREBOX_H
