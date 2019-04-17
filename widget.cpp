#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
        setWindowTitle(tr("角子老虎機"));
        tg_uum=0;
        roll_type=STOP_ROLL;
        myTimer = new QTimer(this);
        m_button = new QPushButton("GO", this);

 //       paintEvent(parent);
        m_button->setGeometry(QRect(QPoint(100, 225),
        QSize(200, 50)));
        roll_num();
        connect(myTimer,SIGNAL(timeout()),this,SLOT(roll_num()));
        connect(m_button, SIGNAL (released()), this, SLOT (handleButton()));

}
/*
Widget::~Widget()
{

}
*/
void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    switch(tg_uum/100)
    {
        case 1:
            pix1.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_1.jpg");
        break;
    case 2:
        pix1.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_2.jpg");
    break;
    case 3:
        pix1.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_3.jpg");
    break;
    case 4:
        pix1.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_4.jpg");
    break;
    case 5:
        pix1.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_5.jpg");
    break;
    default :
        pix1.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_6.jpg");
    break;
    }
    switch((tg_uum%100)/10)
    {
        case 1:
            pix2.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_1.jpg");
        break;
    case 2:
        pix2.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_2.jpg");
    break;
    case 3:
        pix2.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_3.jpg");
    break;
    case 4:
        pix2.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_4.jpg");
    break;
    case 5:
        pix2.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_5.jpg");
    break;
    default :
        pix2.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_6.jpg");
    break;
    }
    switch((tg_uum%100)%10)
    {
        case 1:
            pix3.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_1.jpg");
        break;
    case 2:
        pix3.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_2.jpg");
    break;
    case 3:
        pix3.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_3.jpg");
    break;
    case 4:
        pix3.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_4.jpg");
    break;
    case 5:
        pix3.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_5.jpg");
    break;
    default :
        pix3.load("C:\\Users\\YOHOHO\\Documents\\untitled9\\images\\NUM_6.jpg");
    break;
    }

    painter.drawPixmap(10,10,100,200,pix1);
     painter.drawPixmap(120,10,100,200,pix2);
     painter.drawPixmap(230,10,100,200,pix3);
}
void Widget::roll_num(void)
{
  tg_uum=(unsigned int)generateRandomInteger(100,666)%1000;
 // tg_uum+=1;

   Widget::repaint();
}

int Widget::generateRandomInteger(int min, int max)
{
    Q_ASSERT(min < max);
    static bool seedStatus;
    if (!seedStatus)
    {
        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        seedStatus = true;
    }
    int nRandom = qrand() % (max - min);
    nRandom = min + nRandom;

    return nRandom;
}
void Widget::handleButton(void)
{
    if(roll_type)
    {
        roll_type=STOP_ROLL;
        myTimer->stop();

        if((tg_uum/100)==((tg_uum%100)/10))
        {
            if((tg_uum/100)==((tg_uum%100)%10))
            QMessageBox::warning(this,tr("中獎提示"),tr("恭喜同號連線!!"),QMessageBox::Yes);

        }
          Widget::repaint();
    }
    else
    {
        roll_type=GO_ROLL;
        myTimer->start(100);
    }

}
