#ifndef MAINWINDOW_H
#define	MAINWINDOW_H

#include <QtGui/QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QDateTime>
#include <QTime>
#include <QMainWindow>
#include "MessageEditor.h"
#include "Transmit.h"
#include "Receive.h"
#include "Connection.h"

#include "controller.h"
#include "msg.h"


class MainWindow : public QWidget, public CanListener
{
    Q_OBJECT
    QVBoxLayout *MainLayout;

public:
    MainWindow (QWidget *MainWin, Controller *mContr);

    int notify();
    int errorInNet(const char *str);

    signals:
    void ReceiveSignal(int ID,int DLC,QString DATA,QTime time);

public slots:
    int connect();
    int disconnect();
    void showCredits();


private:
    MessageEditor *MessEd; 
    Transmit *Trans; 
    Receive *Rec;
    Connection *Con;
    Controller *Contr;
};

#endif	/* MAINWINDOW_H */

