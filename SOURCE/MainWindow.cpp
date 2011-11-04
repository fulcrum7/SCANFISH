#include "MainWindow.h"
#include "controller.h"
#include <stdio.h>
#include <string.h>


MainWindow :: MainWindow (QWidget *MainWin, 
        Controller *mContr) : QWidget (MainWin),CanListener()
{
    Contr=mContr;
    MainLayout = new QVBoxLayout;

    MessEd = new MessageEditor(NULL,Contr,Contr->allocMsg());
    Trans = new Transmit(NULL);
    Rec = new Receive(NULL);
    Con = new Connection(NULL,this);

    MainLayout->addWidget(Con);
    MainLayout->addWidget(Rec);
    MainLayout->addWidget(Trans);
    MainLayout->addWidget(MessEd);
    MessEd->setSleep();
    Trans->setFocusPolicy(Qt::NoFocus);
    Rec->setFocusPolicy(Qt::NoFocus);

    QObject::connect (MessEd,SIGNAL(SendSig(QString, QString, QString,QTime)),
            Trans,SLOT(SendSlot(QString, QString, QString,QTime)));

    QObject::connect (this,SIGNAL(ReceiveSignal(int,int,QString,QTime)),Rec,SLOT(ReceiveSlot(int,int,QString,QTime)));

    QObject::connect(Con,SIGNAL(active()),this,SLOT(connect()));
    QObject::connect(Con,SIGNAL(disactive()),this,SLOT(disconnect()));

    QObject::connect(MessEd,SIGNAL(changeNum()),this,SLOT(setCurrentNum()));
    QObject::connect(Con,SIGNAL(changeNum()),this,SLOT(setCurrentNum()));

    setLayout(MainLayout);
}

int MainWindow :: connect()
{
     MessEd->wakeUp();
     std::map <int,CanNet*>::iterator it;
     it=Contr->nettab.find(Contr->netCount);
     num=it->first;
}

int MainWindow :: disconnect()
{
     MessEd->setSleep();
}

int MainWindow :: notify()
{
    unsigned int i;
    QString text;
    char data_element[17];
    Msg *msg;
    Contr->receive(&msg,num);
    for (i=0;i<msg->getDlc();i++)
    {
        sprintf(data_element,"%02X",msg->getData(i));
        text=text+" "+QString::fromAscii(data_element,strlen(data_element));
    }
    QTime time;
    time=((QDateTime::fromTime_t(msg->getTimestampSec())).time());
    time=time.addMSecs(msg->getTimestampMS()/1000);

    emit ReceiveSignal(msg->getID(),msg->getDlc(),text,time);
    msg->setMsgFree();
    return 0;
}

int MainWindow :: errorInNet(const char* str)
{
     QMessageBox msgBox;
     QString string(str);
     QString info("Warning");

     msgBox.setText(string);
     msgBox.setIcon(QMessageBox::Warning);

     msgBox.setWindowTitle(info);
     msgBox.exec();
}


void MainWindow::showCredits()
{
    QLabel *lbl=new QLabel(0);
    QString string;
    string= "\n   release: scanfish 0.1   \n"
            "   license: GPLv3   \n"
            "   source: https://github.com/fulcrum7/SCANFISH   \n"
            "   contacts: scanfishproject@gmail.com\n"
            "   We are waiting for your comments and suggestions   \n"
            "   Let's make CAN development free\n";
    lbl->setFixedWidth(500);
    lbl->setText(string);
    lbl->setWindowTitle("scanfish info");
    lbl->show();
}

int MainWindow::getnum()
{
    return num;
}

void MainWindow::setCurrentNum()
{
    Contr->contrNum=num;
}