#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <QPushButton>
#include<QMessageBox>

#define STOP_ROLL 0
#define GO_ROLL 1
class Widget : public QWidget
{
    Q_OBJECT

public:

    Widget(QWidget *parent = 0);
  //  ~Widget();

    QPixmap pix1;
    QPixmap pix2;
    QPixmap pix3;

     unsigned int tg_uum;
     int generateRandomInteger(int min, int max);
         QTimer *myTimer;
          void paintEvent(QPaintEvent *);
          bool roll_type;
private slots:
         void roll_num(void);
          void handleButton(void);
       private:
         QPushButton *m_button;


};

#endif // WIDGET_H
